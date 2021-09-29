#pragma once
#pragma comment( lib, "ws2_32.lib")

#include <string>

#include <winsock2.h>
#include <Ws2tcpip.h>

class Connection
{
public:
    std::string get_fixed_length_size(std::string message);
    void send_message(std::string message);
    std::string get_message(size_t size);
    std::string recive_message();

    SOCKET get_socket();
    void set_socket(SOCKET socket);

    int get_port_number();
    void set_port_number(int port_number);

    std::string get_username();
    void set_username(std::string username);

    char* get_ip();
    void set_ip(char* ip);
private:
    SOCKET socket;
    int port_number;
    std::string username;
    size_t get_size_from(std::string fixed_length_string);
};

