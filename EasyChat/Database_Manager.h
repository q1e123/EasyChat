#pragma once


#include <memory>

#include "DB_Driver.h"

enum Database_Driver_Type
{
	INI,
	SQLITE
};

namespace Database_Manager
{
	std::shared_ptr<DB_Driver> get_db_driver(Database_Driver_Type database_driver_type, std::string ini_file_path);
}
