#include "Client.h"

Client::Client(int port_number, const std::string ip, const std::string username = "Anon")
{
	if (socket_init() != 0) {
		std::cerr << ("socket init failed") << std::endl;
	}
	SOCKET connection_socket = socket(AF_INET, SOCK_STREAM, 0);
	this->server_connection = std::unique_ptr<Connection>(new Connection(connection_socket, port_number, ip, username));
	if(this->server_connection == nullptr)
	{
		std::cerr << "MEMORY ERROR: server connection" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_number);
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
}

int Client::socket_init() {
	WSADATA wsa_data;
	return WSAStartup(MAKEWORD(1, 1), &wsa_data);
}