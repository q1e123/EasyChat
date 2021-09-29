#include "Connection.h"

#include <iomanip>
#include <sstream>

std::string Connection::get_fixed_length_size(std::string message)
{
	std::stringstream stream;
	stream << std::setw(SIZE_BYTES) << std::setfill('0') << message.size();
	std::string size = stream.str();
	return size;
}
void Connection::send_message(std::string message)
{
    std::string encapsulated_string = get_fixed_length_size(message) + message;
    size_t total_bytes_sent = 0;
    size_t bytes_sent = 0;
    while (total_bytes_sent < encapsulated_string.size()) {
        std::string message_left = encapsulated_string.substr(bytes_sent);
        bytes_sent = send(socket, message_left.c_str(), message_left.size(), 0);
        total_bytes_sent += bytes_sent;
        if (bytes_sent < 0) {
            throw Message_Not_Sent_Exception();
        }
    }
}
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