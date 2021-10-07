#pragma once

#include <map>

#include "SimpleIni.h"

#include "DB_Driver.h"

const size_t HASH_SIZE= 256;

class SimpleIni_Manager : public DB_Driver
{
public:
	SimpleIni_Manager(std::string file_name);
	bool check_authentification(std::string username, std::string password_hash) override;
	void init();
private:
	std::map<std::string, std::string> authentification_map;

	CSimpleIniA ini_file;

	void init_authentification_map();
	bool isUsernameInAuthentificationMap(std::string username);
};

