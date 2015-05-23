//
// Created by chris on 18.05.15.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#include "Connection.h"

Connection::Connection(const std::string &horst, int port) {
    this->host = horst;
    this->port = port;
    _isConnected = makeConnection() > 0;

}

Connection::Connection(const Connection &o) {}

int Connection::makeConnection() {
    // So much ifdef madness .... :D
#ifdef _WIN32
    // This is a winsocks thing and needs doing ... win32 API is terrible btw
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) {
        perror("Failed to finish windows socket preparations WSAStartup()");
        return -1;
    }
#endif

    // protocol family, socket type, something else
    this->socketId = socket(PF_INET, SOCK_STREAM, 0); // Get socket resource

#ifdef _WIN32
    int sockres = static_cast<int>(this->socketId);
#else
    int sockres = socketId;
#endif

    if(sockres < 0) {
        perror("Failed to open Socket.");
        this->closeConnection();
        return -1;
    }

    hostent* hp = gethostbyname(this->host.c_str());
    if(!hp) {
        perror("Could not resolve host name!");
        this->closeConnection();
        return -1;
    }

    sockaddr_in sockIn;
    memset((char*)&sockIn, 0, sizeof(sockIn));
    memcpy((char*)&sockIn.sin_addr, hp->h_addr, hp->h_length);
    sockIn.sin_family = AF_INET; // ipv4
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
#ifdef _WIN32
    closesocket(this->socketId);
    WSACleanup();
#else
    close(this->socketId);
#endif
}

bool Connection::isConnected() {
    return _isConnected;
}

void Connection::sendMessage(const std::string &message) {
    // socket id, message, message size, send flags
    std::cout << "SENDING: " << message << std::endl;
    send(this->socketId, message.c_str(), message.length(), 0);
}

void Connection::readLine(std::string &command) {
    size_t pos;
    // read until we hit line feed

    while ((pos = readBuffer.find("\r\n")) == std::string::npos) {
        char buf[Connection::MAX_BUFFER_SIZE+1]; // +1 for the extra terminating 0 bit that a std::string must have
        ssize_t n = read(this->socketId, buf, Connection::MAX_BUFFER_SIZE);
        if (n == -1) {
            perror("Failed to read from socket!");
            this->readBuffer.clear();
            return;
        }
        buf[n] = 0; // add the terminating 0 char
        readBuffer.append(buf);
    }
    // Strips possible trailing ends
    command.assign(readBuffer.substr(0, pos));
    // +2 to remove the \r\n (2 chars)
    readBuffer = readBuffer.substr(pos+2, readBuffer.length());
}