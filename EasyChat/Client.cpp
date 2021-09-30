#include "Client.h"

Client::Client(int port_number, const std::string ip, const std::string username)
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

Client::~Client() {
	if (reciver.joinable()) {
		reciver.join();
	}
	this->server_name = "";
	this->server_connection.reset();
}

int Client::socket_init() {
	WSADATA wsa_data;
	return WSAStartup(MAKEWORD(1, 1), &wsa_data);
}

void Client::connect_and_auth() {
	try
	{
		connect_to_server();
	}
	catch (Server_Down_Exception exception)
	{
		std::cerr << "server is down" << std::endl;
		exit(EXIT_FAILURE);
	}

	try
	{
		authentification();
	}
	catch (Login_Exception exception)
	{
		std::cerr << "authentification was not successful" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Client::connect_to_server()
{
	SOCKET client_socket = this->server_connection->get_socket();

	if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		throw Server_Down_Exception();
	}
	std::cout << "connection was successful" << std::endl;

}

void Client::authentification()
{
	this->server_connection->send_message(this->server_connection->get_username());
	this->server_name = this->server_connection->recive_message();
	std::string login_response = this->server_connection->recive_message();
	if (login_response == "RETRY") {
		throw Login_Exception();
	}
	std::cout << "login was successful" << std::endl;
}

void Client::start_reciver()
{
	this->reciver = std::thread(&Client::recive_message, this);
}

void Client::recive_message() {
	std::string message = "";
	while (message!= "SOCKET_DOWN") {
		message = this->server_connection->recive_message();
		std::cout << message << std::endl;
	}
}

std::string Client::get_server_name()
{
	return this->server_name;
}

void Client::set_server_name(std::string server_name)
{
	this->server_name = server_name;
}

int Client::socket_close(SOCKET socket) {
	int status = 0;
	status = shutdown(socket, SD_BOTH);
	if (status == 0) {
		status = closesocket(socket);
	}
	return status;
}

