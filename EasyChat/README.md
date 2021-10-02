[![Contributors][contributors-shield]](https://github.com/q1e123/EasyChat/graphs/contributors)
[![Forks][forks-shield]](https://github.com/q1e123/EasyChat/stargazers)
[![Stargazers][stars-shield]](https://github.com/q1e123/EasyChat)
[![Issues][issues-shield]](https://github.com/q1e123/EasyChat)



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

### Built With

* C++ (WinSock)

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these steps.

### System Requiments

TODO

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/q1e123/EasyChat.git
   ```
2. Compile the project using Visual Studio

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
<!-- ROADMAP -->
## Roadmap

If you would like to know more about the future features visit [Trello board](https://trello.com/b/pswIsrQx/easychat)


<!-- LICENSE -->
## License

TBD


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png