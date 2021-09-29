#include "Connection.h"

#include <iomanip>
#include <iostream>
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
std::string Connection::recive_message()
{
	
}

size_t Connection::get_size_from(std::string fixed_length_string)
{
    fixed_length_string.erase(0, std::min(fixed_length_string.find_first_not_of('0'), fixed_length_string.size() - 1));
    size_t size;
    if (fixed_length_string.size() < 1) {
        return 0;
    }
    try {
        size = std::stol(fixed_length_string);
    }
    catch (const std::exception& e) {
        std::cerr << "connection: " << e.what() << " " << fixed_length_string << '\n';
    }

    return size;
}
std::string Connection::get_message(size_t size)
{
	
}
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