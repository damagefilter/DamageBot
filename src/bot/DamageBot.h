/* 
 * File:   DamageBot.h
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 13:42
 */

#ifndef DAMAGEBOT_H
#define	DAMAGEBOT_H
#include "../networking/Connection.h"

#include <list>
#include <string>

class DamageBot {
public:
    DamageBot(const char* _nick, const char* _user, const char* _owner);
    
    /**
     * Initialise the bot, connect to the server that was passed in the constructor
     */
    void init();
    
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
    bool doPong(std::string& message);
    
    /**
     * Does the login honky tonky at the connected IRC server
     * @param password  the password to authenticate at a nickserv.
     *                  pass 0 to not do nickserv auth
     */
    void login(const char* password);
    
    void processMessage();
    
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
    
    void quit(std::string& message, bool terminate);
    
    std::string& getNick() {
        return this->nick;
    }
    
    std::string& getUser() {
        return this->user;
    }
    
    std::string& getOwner() {
        return this->owner;
    }
 
private:
    char messageBuffer[Connection::MAX_BUFFER_SIZE];
    std::string nick;
    std::string user;
    std::string owner;
    Connection* con;
    // Channels we're connected to
    std::list<std::string> channels;
    std::string activeChannel;
};

#endif	/* DAMAGEBOT_H */

