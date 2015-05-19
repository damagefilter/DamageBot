//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_IRCBOT_H
#define IRCBOT_IRCBOT_H

#include "../networking/Connection.h"
#include "../events/EventHandler.h"

#include <list>
#include <string>
#include <vector>


class IrcBot {
public:
    IrcBot(const std::string &_nick, const std::string &_user, const std::string &_owner);

    /**
     * Initialise the bot, connect to the server that was passed in the constructor
     */
    void init();

    /**
     * Sends a message to the currently active channel
     * @param message the message
     */
    void sendChannelMessage(const std::string &message);

    /**
     * Send a message to a specified user
     * @param message
     * @param user
     */
    void sendPrivateMessage(const std::string &message, const std::string &user);

    /**
     * Used to respond to ping requests from an IRC server
     * @param message
     */
    bool doPong(const std::string &message);

    /**
     * Does the login honky tonky at the connected IRC server
     * @param password  the password to authenticate at a nickserv.
     *                  pass 0 to not do nickserv auth
     */
    void login(const std::string &password);

    void processMessage();

    /**
     * Joins a new channel
     * @param channel
     */
    void joinChannel(const std::string &channel);

    /**
     * Leave the given channel.
     * @param channel
     */
    void partChannel(const std::string &channel);

    void quit(const std::string &message, bool terminate);

    /**
     * Add an event handler to the bot.
     * The bot will take care of freeing themup when they are not required anymore.
     *
     * @param handler the handler to add
     */
    void addHandler(EventHandler* handler);

    std::string& getNick() {
        return this->nick;
    }

    std::string& getUser() {
        return this->user;
    }

    std::string& getOwner() {
        return this->owner;
    }

    /**
     * Set the active channel the bot is speaking to.
     */
    void setActiveChannel(const std::string& channel) {
        this->activeChannel = channel;
    }

private:
    std::string messageBuffer;
    std::string nick;
    std::string user;
    std::string owner;
    Connection* con;
    // Channels we're connected to
    std::vector<std::string> channels;
    std::string activeChannel;
    std::vector<EventHandler*> handlerList;
    bool motdFinished;
};


#endif //IRCBOT_IRCBOT_H
