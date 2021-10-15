#pragma once
#include "DB_Driver.h"

#include <memory>
#include <string>
#include <vector>

#include <sqlite3.h>

typedef std::vector<std::vector<std::string>> Table;

class SQLite_Manager : public DB_Driver
{
public:
	SQLite_Manager(std::string database_file_path);
	void add_user(std::string username, std::string password_hash) override;
	bool check_authentification(std::string username, std::string password_hash) override;
private:
	std::string database_file_path;
	std::shared_ptr<sqlite3> database;

	static int callback(void* data, int entries_number, char** entries, char** col_names);
	void create_user_table();
};
