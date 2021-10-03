#include "Server.h"

#include <iostream>

#include "Utils.h"

Server::Server(std::string name, size_t port) {
	this->name = name;
	
	this->server_connection = std::unique_ptr<Connection>(new Connection(port, LOOPBACK_ADDR, "SERVER"));
	struct addrinfo hints;
	struct addrinfo* server = NULL;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	const char OPTION_VALUE = 1;

	getaddrinfo(LOOPBACK_ADDR, std::to_string(port).c_str(), &hints, &server);
	server_sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &OPTION_VALUE, sizeof(int)); //Make it possible to re-bind to a port that was used within the last 2 minutes
	setsockopt(server_sock, IPPROTO_TCP, TCP_NODELAY, &OPTION_VALUE, sizeof(int)); //Used for interactive programs


	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_number);

	InetPton(AF_INET, (PCWSTR)LOOPBACK_ADDR, &server_addr.sin_addr.s_addr);

	client_addr_size = sizeof(client_addr);

	if (bind(server_sock, server->ai_addr, (int)server->ai_addrlen) != 0) {
		std::cerr << "binding unsuccessful" << std::endl << WSAGetLastError() <<std::endl;
		exit(1);
	}

	if (listen(server_sock, SOMAXCONN) != 0) {
		std::cerr << "listening unsuccessful" << std::endl;
		exit(1);
	}
}

void Server::start() {
	while (1) {
		SOCKET client_sock;
		client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);

		mtx.lock();
		char ip_c[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, (struct sockaddr*)&client_addr, ip_c, INET_ADDRSTRLEN);
		std::string ip = std::string(ip_c);
		std::cout << "connection successful " << ip << std::endl;
		std::shared_ptr<Connection> client_connection = std::shared_ptr<Connection>(new Connection());
		if (client_connection == nullptr)
		{
			Utils::memory_error();
		}
		client_connection->set_socket(client_sock);
		std::string username = client_connection->recive_message();
		client_connection->set_username(username);

		client_connection->send_message(this->name);

		std::string login_message;
		if (true)
		{
			login_message = "OK";
		}
		else
		{
			login_message = "RETRY";
		}

		client_connection->send_message(login_message);
		if (login_message == "OK") {
			this->username_connection_map[username] = client_connection;
			std::thread worker(&Server::reciver, this, client_connection);
			workers[client_connection] = std::move(worker);
		}
		client_connection->send_message("Welcome to " + this->name);
		this->notify_users_new_connection(username);
		mtx.unlock();
	}

	for (auto const& item : this->workers){
		if (workers[item.first].joinable()) {
			workers[item.first].join();
		}
	}
}

void Server::reciver(std::shared_ptr<Connection> client_connection) {
	std::string username = client_connection->get_username();
	std::cout << "reciver started for " << username << std::endl;
	std::string message;
	try {
		while (message != "SOCKET_DOWN") {
			message = client_connection->recive_message();
			send_to_all(username, message);
		}
	}
	catch (Client_Down_Exception exception) {
		std::cout << username << " has disconnected" << std::endl;
		this->remove_user(client_connection);
	}
}

void Server::remove_user(std::shared_ptr<Connection> connection)
{
	mtx.lock();
	std::string username = connection->get_username();
	this->username_connection_map.erase(username);
	this->workers.erase(connection);
	mtx.unlock();

}

std::string Server::get_wrapped_message(std::string username, std::string message)
{
	std::string wrapped_message = username + ": " + message;
	return wrapped_message;
}

void Server::send_to_all(std::string username, std::string message) {
	mtx.lock();
	std::string pkg = "";
	std::string wrapped_message = this->get_wrapped_message(username, message);
	for (auto const& item : this->username_connection_map) {
		if(item.first != username)
		{
			item.second->send_message(wrapped_message);
		}
	}
	mtx.unlock();
	std::this_thread::sleep_for(WAIT_PERIOD);
}

void Server::notify_users_new_connection(std::string username)
{
	std::string message = username + " has connected";
	for (auto const& item : this->username_connection_map) {
		if (item.first != username)
		{
			item.second->send_message(message);
		}
	}
	std::this_thread::sleep_for(WAIT_PERIOD);
}
