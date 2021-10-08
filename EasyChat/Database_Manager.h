#pragma once


#include <memory>

#include "SimpleIni_Manager.h"

enum Database_Driver_Type
{
	INI
};

namespace Database_Manager
{
	std::shared_ptr<DB_Driver> get_db_driver(Database_Driver_Type database_driver_type, std::string ini_file_path);
}
