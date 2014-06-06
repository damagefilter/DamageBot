/* 
 * File:   Connection.h
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 14:02
 */

#ifndef CONNECTION_H
#define	CONNECTION_H

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif

/**
 Represents a TCP Socket connection
 */
class Connection {
private:
    int port; // port to connect to
    char* host; // host to connect to
#ifdef WIN32
    SOCKET socketId;
#else
    int socketId;
#endif
    
public:
    Connection(char* host, int port);
    /**
     * Initiates a stream socket connection
     * @return the resource handle or -1 on failure
     */
    int makeConnection();
    
    /**
     * Closes the stream socket and releases the resource handle
     */
    void closeConnection();
    
    /**
     * Sends the given string via the socket to the upstream.
     * @param message the message to send
     */
    void sendMessage(const char* message);
private:
    
    Connection(const Connection& c);
    void operator=(const Connection& c);
};

#endif	/* CONNECTION_H */

