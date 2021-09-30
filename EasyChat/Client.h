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

class Client
{
public:
	Client(int port_number, const std::string ip, const std::string username = "Anon");
	~Client();
private:
	std::unique_ptr<Connection> server_connection;
	struct sockaddr_in server_addr;

	int socket_init();
	int socket_quit();
	bool socket_check(SOCKET socket);
	int socket_close(SOCKET socket);
};

