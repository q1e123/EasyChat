#include "Connection.h"

std::string Connection::get_fixed_length_size(std::string message{

};
void Connection::send_message(std::string message);
std::string Connection::get_message(size_t size);
std::string Connection::recive_message();

SOCKET Connection::get_socket()
{
	return this->socket;
}
void Connection::set_socket(SOCKET socket)
{
	this->socket = socket;
}

int Connection::get_port_number()
{
	return this->port_number;
}
void Connection::set_port_number(int port_number)
{
	this->port_number = port_number;
}

std::string Connection::get_username()
{
	return this->username;
}
void Connection::set_username(std::string username)
{
	this->username = username;
}