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

#include "PropertiesReader.h"
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
    const char* host; // host to connect to
#ifdef WIN32
    SOCKET socketId;
#else
    int socketId;
#endif
    
public:
    static const int MAX_BUFFER_SIZE = 4096;
    /**
     * Get the connection instance
     * @return the connection instance
     */
    static Connection* instance() {
        static PropertiesReader reader("bot.cfg");
        static Connection* $ = new Connection(reader.getString("host"), reader.getInteger("port"));
        return $;
    }
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
     * Check if this Connection is properly connected to the endpoint
     * @return 
     */
    bool isConnected();
    
    /**
     * Sends the given data via the socket to the upstream.
     * @param message the message to send
     */
    void sendMessage(const char* message);
    
    /**
     * Reads from the stream socket and fills the given buffer with data
     * @param buffer
     */
    void read(char* buffer);
private:
    Connection(const char* host, int port);
    Connection(const Connection& c);
    void operator=(const Connection& c);
    
    bool _isConnected;
};

#endif	/* CONNECTION_H */

