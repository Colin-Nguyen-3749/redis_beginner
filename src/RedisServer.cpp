#include "include/RedisServer.h"

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

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
    if (server_socket < 0) {
        std::cerr << "Error creating server socket" << endl;
        return;
    }

    int
}