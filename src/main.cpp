#include <iostream>

int main(int argc, char* argv[]) {
    
    // default port
    int port = 6379;
    if (argc >= 2) {
        port = std::stoi(argv[1]);
    }
    
    return 0;
}