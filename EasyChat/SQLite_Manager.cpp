#include "SQLite_Manager.h"

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
}

void SQLite_Manager::add_user(std::string username, std::string password_hash)
{
	return;
}

bool SQLite_Manager::check_authentification(std::string username, std::string password_hash)
{
    return true;
}

