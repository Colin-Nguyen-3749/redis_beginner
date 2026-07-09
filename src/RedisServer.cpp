#include "include/RedisServer.h"

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

static RedisServer* globalServer = nullptr;

RedisServer::RedisServer(int port) : port(port), server_socket(-1), running(true) {
    globalServer = this;

}

void RedisServer::shutdown() {
    running = false;
    if (server_socket != -1) {
        close(server_socket);
    }

    std::cout << "Server Shutdown Complete!" << endl; 
}

void RedisServer::run() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0):
    
    // get socket
    if (server_socket < 0) {
        std::cerr << "Error creating server socket" << endl;
        return;
    }

    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADOR, &opt, sizeof(opt));

    sokaddr_in serverAddr();
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // change -1 to something different if we are connecting to a server using
    // sockets
    if (bind(server_socket, (struct sockadd*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding server socket" << endl;
        return;
    }

    // if binding and listening is successful, we have connected to the right port
    // are listening to it
    if (listen(server_socket, 10) < 0) {
        std::cerr << "Error listening on server socket" << endl;
        return;
    }

    std::cout << "Redis server listening on port " << port << endl;

}