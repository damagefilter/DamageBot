//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_CONNECTION_H
#define IRCBOT_CONNECTION_H

#if defined(WIN32) || defined(_WIN32)
#include <winsock2.h>
#else
// In Linux we need a little more stuff for inclusion
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif

#include "../tools/PropertiesReader.h"
#include <vector>


class Connection {
private:
    int port; // port to connect to
    std::string host; // host to connect to
#ifdef _WIN32
    SOCKET socketId;
#else
    int socketId;
#endif

public:
    static const int MAX_BUFFER_SIZE = 4096;
    std::string readBuffer;
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
    void sendMessage(const std::string &message);

    /**
     * Reads from the connection until a line feed is reached.
     * Then assigned the read-out buffer to the command string
     *
     * @param buffer
     */
    void readLine(std::string &command);
private:
    Connection(const std::string &host, int port);
    Connection(const Connection& c);
    void operator=(const Connection& c);

    bool _isConnected;
};
#endif //IRCBOT_CONNECTION_H
