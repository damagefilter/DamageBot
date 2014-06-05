#include <stdio.h>

#include "Connection.h"

Connection::Connection(char* host, int port) {
    this->host = host;
    this->port = port;
}

int Connection::makeConnection() {
    // So much ifdef madness .... :D
#ifdef WIN32
    // This is a winsocks thing and needs doing ... win32 API is terrible btw
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) {
        perror("Failed to finish windows socket preparations WSAStartup()");
        return -1;
    }
#endif
    
    this->socketId = socket(AF_INET, SOCK_STREAM, 0); // Get socket resource
    
#ifdef WIN32
    int sockres = static_cast<int>(this->socketId);
#else
    int sockres = socketId;
#endif
    
    if(sockres < 0) {
        perror("Failed to open Socket.");
        this->closeConnection();
        return -1;
    }
    
    hostent* hp = gethostbyname(this->host);
    if(!hp) {
        perror("Could not resolve host name!");
        this->closeConnection();
        return -1;
    }
    
    sockaddr_in sockIn;
    memset((char*)&sockIn, 0, sizeof(sockIn));
    sockIn.sin_family = AF_INET; // ipv4
    memcpy((char*)&sockIn.sin_addr, hp->h_addr, hp->h_length);
    sockIn.sin_port = htons(this->port); // port in tcp/ip byte order (big endian))
    memset(&(sockIn.sin_zero), 0, 8 * sizeof(char));
    if(connect(this->socketId, (sockaddr*)&sockIn, sizeof(sockIn)) == -1) {
        perror("Failed to establish connection!");
        this->closeConnection();
        return -1;
    }
    // Okay, done, all cool
    return 1;
}

void Connection::closeConnection() {
#ifdef WIN32
    closesocket(this->socketId);
    WSACleanup();
#else
    close(this->socketId);
#endif
}

void Connection::sendMessage(const char* message) {
    // socket id, message, message size, send flags
    send(this->socketId, message, strlen(message), 0);
}