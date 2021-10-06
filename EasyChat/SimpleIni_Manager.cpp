#include "SimpleIni_Manager.h"

#include <iostream>

SimpleIni_Manager::SimpleIni_Manager(std::string file_name)
{
	if (this->ini_file.LoadFile(file_name.c_str()) < 0) {
		std::cerr << "Can't open database init file" << std::endl;
		exit(1);
	}
	this->init_authentification_map();
}
bool SimpleIni_Manager::check_authentification(std::string username, std::string password)
{
	if(this->isUsernameInAuthentificationMap(username))
	{
		bool query_result = (this->authentification_map[username] == password) ? true : false;
		return query_result;
	}
	return false;
}

void SimpleIni_Manager::init_authentification_map()
{
	size_t number_of_users = std::stol(this->ini_file.GetValue("users", "number_of_users_to_be_created"));
	for (size_t i = 0; i < number_of_users; ++i) {
		std::string object = "user" + std::to_string(i);

		std::string user_key = object + ".user";
		std::string user = this->ini_file.GetValue("users", user_key.c_str());
		std::string password_key = object + ".password";
		std::string password_hash = this->ini_file.GetValue("users", password_key.c_str());
		this->authentification_map[user] = password_hash;

	}

}

bool SimpleIni_Manager::isUsernameInAuthentificationMap(std::string username)
{
	if(this->authentification_map[username].length() < HASH_SIZE)
	{
		return false;
	}
	return true;
}