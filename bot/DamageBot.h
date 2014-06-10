/* 
 * File:   DamageBot.h
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 13:42
 */

#ifndef DAMAGEBOT_H
#define	DAMAGEBOT_H
#include "../Connection.h"

#include <list>

class DamageBot {
public:
    DamageBot(const char* _nick, const char* _user);
    
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
    const char* nick;
    const char* user;
    Connection* con;
    
    // Channels we're connected to
    std::list<std::string> channels;
    std::string activeChannel;
    
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
     * Does the login honky tonky at the connected IRC server
     * @param password  the password to authenticate at a nickserv.
     *                  pass 0 to not do nickserv auth
     */
    void login(const char* password);
    
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

