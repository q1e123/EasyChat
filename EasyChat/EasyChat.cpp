#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <Windows.h>
#include <windef.h>

#include "Client.h"
#include "Server.h"
#include "Utils.h"

using namespace std;

int main(int argc, char* argv[])
{
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(1, 1), &wsa_data);
	std::vector<std::string> parameter_list(argv + 1, argv + argc);

	auto server_param_iterator = std::find(parameter_list.begin(), parameter_list.end(), "-server");
	if(server_param_iterator != parameter_list.end())
	{
		auto server_name_iterator = std::next(server_param_iterator, 1);
		auto server_port_it = std::next(server_param_iterator, 2);

		std::string server_name = *server_name_iterator;
		std::string server_port_string = *server_port_it;

		size_t server_port = Utils::string_to_size_t(server_port_string);

		std::cout << "creating server with options:" << std::endl;
		std::cout << "name: " << server_name << std::endl;
		std::cout << "port: " << server_port << std::endl;

		Database_Driver_Type driver_type;
		std::string file_name;

		auto ini_db_driver_iterator = std::find(parameter_list.begin(), parameter_list.end(), "-ini");
		if(ini_db_driver_iterator != parameter_list.end())
		{
			driver_type = Database_Driver_Type::INI;
			auto file_name_iterator = std::next(ini_db_driver_iterator, 1);
			file_name = *file_name_iterator;

		}
		auto sqlite_db_driver_iterator = std::find(parameter_list.begin(), parameter_list.end(), "-sqlite");
		if (sqlite_db_driver_iterator!= parameter_list.end())
		{
			driver_type = Database_Driver_Type::SQLITE;
			auto file_name_iterator = std::next(sqlite_db_driver_iterator, 1);
			file_name = *file_name_iterator;

		}

		std::unique_ptr<Server> server(new Server(server_name, server_port));
		server->connect_to_database(driver_type, file_name);
		server->start();
	}
	auto client_param_iterator = std::find(parameter_list.begin(), parameter_list.end(), "-client");
	if (client_param_iterator != parameter_list.end())
	{
		auto username_iterator = std::next(client_param_iterator, 1);
		auto password_iterator = std::next(client_param_iterator, 2);
		auto server_ip_iterator = std::next(client_param_iterator, 3);
		auto server_port_iterator = std::next(client_param_iterator, 4);

		std::string username = *username_iterator;
		std::string password = *password_iterator;
		std::string server_ip = *server_ip_iterator;
		std::string server_port_string = *server_port_iterator;
		size_t server_port = Utils::string_to_size_t(server_port_string);

		std::cout << "attempting to connect to " << server_ip << ":" << server_port << " as " << username << std::endl;

		std::unique_ptr<Client> client(new Client(server_port, server_ip));
		client->connect_and_auth(username, password);
		client->start_reciver();
		client->sender();
	}
	WSACleanup();
}