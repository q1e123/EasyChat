#include "SimpleIni_Manager.h"

#include <iostream>

SimpleIni_Manager::SimpleIni_Manager()
{
	
}

SimpleIni_Manager::SimpleIni_Manager(std::string file_name)
{
	this->ini_file_name = file_name;
	this->open_ini_file(file_name);
}

bool SimpleIni_Manager::check_authentification(std::string username, std::string password_hash)
{
	if(this->isUsernameInAuthentificationMap(username))
	{
		bool query_result = (this->authentification_map[username] == password_hash) ? true : false;
		return query_result;
	}
	return false;
}

void SimpleIni_Manager::add_user(std::string username, std::string password_hash)
{
	if(this->isUsernameInAuthentificationMap(username))
	{
		return;
	}
	++this->last_id;
	std::string object = "user" + std::to_string(this->last_id);
	std::string user_key = object + ".user";
	std::string password_key = object + ".password_hash";
	this->ini_file.SetValue("users", user_key.c_str(), username.c_str());
	this->ini_file.SetValue("users", password_key.c_str(), password_hash.c_str());
	this->ini_file.SaveFile(this->ini_file_name.c_str());
	this->authentification_map[username] = password_hash;
}

void SimpleIni_Manager::init_authentification_map()
{
	size_t number_of_users = std::stol(this->ini_file.GetValue("users", "number_of_users_to_be_created"));
	this->last_id = number_of_users - 1;
	for (size_t i = 0; i < number_of_users; ++i) {
		std::string object = "user" + std::to_string(i);

		std::string user_key = object + ".user";
		std::string user = this->ini_file.GetValue("users", user_key.c_str());
		std::string password_key = object + ".password_hash";
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

void SimpleIni_Manager::open_ini_file(std::string file_name)
{
	if (this->ini_file.LoadFile(file_name.c_str()) < 0) {
		std::cerr << "Can't open database init file" << std::endl;
		exit(1);
	}
	this->init_authentification_map();
}

void SimpleIni_Manager::add_authentification_entry(std::string username, std::string status, std::string ip)
{
	return;
}
