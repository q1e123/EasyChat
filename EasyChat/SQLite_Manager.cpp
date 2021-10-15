#include "SQLite_Manager.h"

#include <iostream>

#include "Utils.h"

SQLite_Manager::SQLite_Manager(std::string database_file_path)
{
    this->database_file_path = database_file_path;
    this->database = std::shared_ptr<sqlite3>(nullptr);
    auto database_pointer = this->database.get();
    size_t return_code = sqlite3_open(database_file_path.c_str(), &database_pointer);
    this->database.reset(database_pointer);

    if(return_code)
    {
        std::cerr << "can't open SQLite database" << std::endl;
        exit(1);
    } else
    {
        std::cout << "SQLite database opened successfully" << std::endl;
    }
    this->create_user_table();
}

int SQLite_Manager::callback(void* data, int entries_number, char** entries, char** col_names) {
    Table* table = static_cast<Table*>(data);
    try {
        table->emplace_back(entries, entries + entries_number);
    }
    catch (...) {
        return 1;
    }
}

void SQLite_Manager::create_user_table()
{
    Table return_table;
    std::cout << "creating user table if it dosen't exists" << std::endl;
    std::string query = Utils::get_query("SQL/create-user-table.sql");
	char* zErrMsg = 0;
    sqlite3_exec(this->database.get(), query.c_str(), this->callback, &return_table, &zErrMsg);

}


void SQLite_Manager::add_user(std::string username, std::string password_hash)
{
	return;
}

bool SQLite_Manager::check_authentification(std::string username, std::string password_hash)
{
    Table return_table;
    std::string query = Utils::get_query("SQL/check-authentification.sql");
    Utils::replace(query, "USERNAME", username);
    Utils::replace(query, "PASSWORD", password_hash);
    char* zErrMsg = 0;
    sqlite3_exec(this->database.get(), query.c_str(), this->callback, &return_table, &zErrMsg);
    if(return_table.size() < 1)
    {
        return true;
    }
    return false;
}

