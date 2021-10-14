#pragma once
#include <iostream>

#include "DB_Driver.h"

#include <memory>
#include <string>

#include <sqlite3.h>

class SQLite_Manager : public DB_Driver
{
public:
	SQLite_Manager(std::string database_file_path);
	void add_user(std::string username, std::string password_hash) override;
	bool check_authentification(std::string username, std::string password_hash) override;
private:
	std::string database_file_path;
	std::shared_ptr<sqlite3> database;

	void create_user_table();


};