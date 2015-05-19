#include <string.h>
#include <iostream>
#include <stdexcept>
#include<algorithm>
#include "IrcBot.h"
#include "../events/ChatEvent.h"

IrcBot::IrcBot(const std::string &_nick, const std::string &_user, const std::string &_owner) {
    this->nick = _nick;
    this->user = _user;
    this->owner = _owner;
    this->motdFinished = false;
}

void IrcBot::init() {
    this->con = Connection::instance();
}

bool IrcBot::doPong(const std::string& message) {
    // "Real" pings are the ones where the message string starts with PING.
    if(StringLib::startsWith(message, "PING")) {
        unsigned long pingPos = message.find("PING");
        this->con->sendMessage("PONG"+message.substr(pingPos+4)+"\r\n");
        return true;
    }
    return false;
}

void IrcBot::login(const std::string& password) {
    std::string buf;
    this->con->sendMessage(buf.append("NICK ").append(this->nick).append("\r\n"));
    buf.clear();

    this->con->sendMessage(buf.append("USER ").append(this->nick).append(" 0 * :").append(this->user).append("\r\n"));
    buf.clear();
    if (password.length() > 0) {
        this->con->sendMessage(buf.append("PRIVMSG NickServ IDENTIFY ").append(password).append("\r\n"));
        buf.clear();
    }
}

void IrcBot::sendChannelMessage(const std::string& message) {
    std::string toSend("PRIVMSG #"+this->activeChannel+" :"+message+"\r\n");
    this->con->sendMessage(toSend);
}

void IrcBot::sendPrivateMessage(const std::string& message, const std::string& user) {
    this->con->sendMessage("PRIVMSG "+user+" :"+message+"\r\n");
}

void IrcBot::processMessage() {
    // Empty the string
    this->con->readLine(messageBuffer);
    std::cout << messageBuffer << std::endl;
    if(!doPong(messageBuffer)) {
        EventDispatcher::instance()->call(new ChatEvent(messageBuffer));
    }
    // Not in any channel
    if (!this->motdFinished && channels.size() == 0) {
        if (messageBuffer.find("/MOTD") != std::string::npos) {
            this->joinChannel("some_channel"); // TODO: read from cfg
            this->motdFinished = true;
        }
    }
}

void IrcBot::addHandler(EventHandler *handler) {
    this->handlerList.push_back(handler);
}


void IrcBot::joinChannel(const std::string &channel) {
    this->con->sendMessage("JOIN #" + channel + "\r\n");
    this->activeChannel = channel;
    this->channels.push_back(channel);
}

void IrcBot::partChannel(const std::string &channel) {
//    StringLib::trim(channel, "\r\n");
    this->con->sendMessage("PART #" + channel + "\r\n");
    auto it = std::find(this->channels.begin(), this->channels.end(), channel);
    if (it != this->channels.end()) {
        this->channels.erase(it);
    }

}

void IrcBot::quit(const std::string &message, bool terminate) {
//    StringLib::trim(message, "\r\n");
    this->con->sendMessage("QUIT :" + message + "\r\n");
    if (terminate) {
        this->con->closeConnection();
        exit(0); // Normal termination
    }
}
