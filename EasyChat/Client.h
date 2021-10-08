#pragma once
#pragma comment( lib, "ws2_32.lib")

#include <thread>
#include <iostream>
#include <string>

#include <winsock2.h>

#include "Connection.h"

class Server_Down_Exception : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Server is down";
	}private:
};

class Login_Exception : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Authentification failed";
	}
private:
};

class Client
{
public:
	Client(int port_number, const std::string ip);
	~Client();

	void connect_and_auth(std::string username, std::string password);
	void start_reciver();
	void sender();

	std::string get_server_name();
	void set_server_name(std::string server_name);
private:
	std::string server_name;
	std::thread reciver;

	std::shared_ptr<Connection> server_connection;
	struct sockaddr_in server_addr;

	void connect_to_server();
	void authentification(std::string username, std::string password);
	void recive_message();
};

