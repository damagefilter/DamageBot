/* 
 * File:   DamageBot.h
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 13:42
 */

#ifndef DAMAGEBOT_H
#define	DAMAGEBOT_H
#include "../Connection.h"

class DamageBot {
public:
    DamageBot(char* _nick, char* _user, char* host, int port);
//    virtual ~DamageBot();
    bool setup;
    
    /**
     * Initialise the bot, connect to the server that was passed in the constructor
     */
    void init();
    
    /**
     * Conduct a search within a given char array haystack,
     * for the given char array needle
     * @param haystack
     * @param needle
     * @return 
     */
    bool charSearch(char *haystack, char *needle);
 
private:
    char* nick;
    char* user;
    char* host;
    int port;
    Connection* con;
    
    // Channels we're connected to
    std::list<std::string> channels;
    std::string& activeChannel;
    
    /**
     * Sends a message to the currently active channel
     * @param message the message
     */
    void sendChannelMessage(std::string& message);
    
    /**
     * Send a message to a specified user
     * @param message
     * @param user
     */
    void sendPrivateMessage(std::string& message, std::string& user);
    
    /**
     * Used to respond to ping requests from an IRC server
     * @param message
     */
    void doPong(std::string& message);
    
    /**
     * Joins a new channel
     * @param channel
     */
    void joinChannel(std::string& channel);
    
    /**
     * Leave the given channel.
     * @param channel
     */
    void partChannel(std::string& channel);

};

#endif	/* DAMAGEBOT_H */

