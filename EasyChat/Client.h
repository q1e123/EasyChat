#pragma once
#pragma comment( lib, "ws2_32.lib")

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include <vector>

#include <winsock2.h>
#include <Ws2tcpip.h>

#include "Connection.h"

class Server_Down_Exception : public std::exception {
public:
	virtual const char* what() const throw();
private:
};

class Login_Exception : public std::exception {
public:
	virtual const char* what() const throw();
private:
};

class Client
{
public:
	Client(int port_number, const std::string ip, const std::string username = "Anon");
	~Client();

	void connect_and_auth();
	void start_reciver();

	std::string get_server_name();
	void set_server_name(std::string server_name);
private:
	std::string server_name;
	std::thread reciver;

	std::unique_ptr<Connection> server_connection;
	struct sockaddr_in server_addr;

	void connect_to_server();
	void authentification();
	void recive_message();

	int socket_init();
	int socket_close(SOCKET socket);
};

