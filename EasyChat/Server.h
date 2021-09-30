#pragma once
#pragma comment( lib, "ws2_32.lib")
#include <winsock2.h>
#include <Ws2tcpip.h>

#include <thread>
#include <mutex>
#include <vector>
#include <map>
#include <sstream>

#include "Connection.h"

#define LOOPBACK_ADDR	"127.0.0.1"
#define DEFAULT_PORT 50005

class Server {
public:
	Server(std::string name, size_t port = DEFAULT_PORT);
	void start();
private:
	std::string name;

	std::thread send_worker;

	std::mutex mtx;
	std::map<std::string, std::unique_ptr<Connection>> username_connection_map;
	std::unique_ptr<Connection> server_connection;
	std::map<size_t, std::thread> workers;
	std::map<std::string, std::string> systems;

	struct sockaddr_in server_addr, client_addr;
	SOCKET server_sock;
	socklen_t client_addr_size;
	int port_number;

	void send_to_all();
};