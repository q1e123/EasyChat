<!-- PROJECT LOGO -->
<br />
<p align="center">
  <h3 align="center">EasyChat</h3>

  <p align="center">
    Chat application
    <br>
    <a href="https://github.com/q1e123/EasyChat/issues">Report a bug or request a feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">System Requiments</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

TODO

### Features

* public chat room
* connection/ disconnection notifications
* get online users command (/online) 
* authentification using ini files
* adding new users using /add command

### Built With

* C++ (WinSock, OpenSSL)

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these steps.

### Prerequisites
[1. Build OpenSSL library for C++](https://www.youtube.com/watch?v=PMHEoBkxYaQ)

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/q1e123/EasyChat.git
   ```
2. Compile the project using Visual Studio
3. Copy DLLs from *OpenSSL* to executable directory.

<!-- USAGE EXAMPLES -->
## Usage


### Server
```sh
.\EasyChat.exe -server <server_name> <server_port>
```

#### server_name
The name of the server

#### server_port
The port that will be used by the server.

#### Example

```sh
.\EasyChat.exe -server chat_room 50005
```

### Client
```sh
.\EasyChat.exe -client <username> <server_ip> <server_port>
```

#### username
The username that will be used in chat.

#### server_ip
The ip of the server

#### server_port
The port that is used by the server.

```sh
.\EasyChat.exe -client test 192.168.56.1 50005
```

### Authentification
For authentification you can use an ini file. For a template you can look at *users-template.ini* file.

### Adding new users
To add new users go to the server application and use the following command:
```
/add <username> <password>
```
<!-- ROADMAP -->
## Roadmap

If you would like to know more about the future features visit [Trello board](https://trello.com/b/pswIsrQx/easychat)


<!-- LICENSE -->
## License

TBD


