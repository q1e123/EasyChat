#pragma once
#pragma comment( lib, "ws2_32.lib")

#include <string>

#include <winsock2.h>

#define BUFFER_SIZE 65536
#define SIZE_BYTES 10

class Message_Not_Sent_Exception : public std::exception {
    virtual const char* what() const throw() {
        return "Message was not sent";
    }
};

class Socket_Error_Exception : public std::exception {
    virtual const char* what() const throw() {
        return "Unknown socket error";
    }
};

class Client_Down_Exception : public std::exception {
    virtual const char* what() const throw() {
        return "Client down";
    }
};


class Connection
{
public:
    Connection(int port_number, const std::string ip, const std::string username = "Anon");
    ~Connection();
    std::string get_fixed_length_size(std::string message);
    void send_message(std::string message);
    std::string recive_message();

    SOCKET get_socket();
    void set_socket(SOCKET socket);

    int get_port_number();


    void set_port_number(int port_number);

    std::string get_username();
    void set_username(std::string username);

	std::string get_ip();
    void set_ip(std::string ip);
	
private:
    int port_number;

    std::string username;
    std::string ip;

	SOCKET sock;

	size_t get_size_from(std::string fixed_length_string);
    std::string get_message(size_t size);
    int socket_init();
    int socket_close();
};

