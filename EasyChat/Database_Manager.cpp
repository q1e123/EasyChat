#include "Database_Manager.h"
std::shared_ptr<DB_Driver> Database_Manager::get_db_driver(Database_Driver_Type database_driver_type)
{
	switch (database_driver_type)
	{
	case Database_Driver_Type::INI:
		{
			std::shared_ptr<DB_Driver> driver(new SimpleIni_Manager());
		}
	}
}