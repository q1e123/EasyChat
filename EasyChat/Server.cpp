#include "Server.h"

#include <iostream>

Server::Server(std::string name, size_t port) {
	this->name = name;
	
	server_sock = socket(AF_INET, SOCK_STREAM, 0);
	this->server_connection = std::unique_ptr<Connection>(new Connection(port, LOOPBACK_ADDR, "SERVER"));
	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_number);

	InetPton(AF_INET, (PCWSTR)LOOPBACK_ADDR, &server_addr.sin_addr.s_addr);

	client_addr_size = sizeof(client_addr);

	if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
		std::cerr << "binding uunsuccessful" << std::endl;
		exit(1);
	}

	if (listen(server_sock, 5) != 0) {
		std::cerr << "listening unsuccessful" << std::endl;
		exit(1);
	}
}