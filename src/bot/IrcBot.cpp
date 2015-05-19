#include <string.h>
#include <iostream>
#include <stdexcept>
#include<algorithm>
#include "IrcBot.h"
#include "../events/ChatEvent.h"
//#include "../events/EventDispatcher.h"
//#include "../events/ChatEvent.h"

IrcBot::IrcBot(const std::string &_nick, const std::string &_user, const std::string &_owner) {
    this->nick = _nick;
    this->user = _user;
    this->owner = _owner;
}

void IrcBot::init() {
    this->con = Connection::instance();
}

bool IrcBot::doPong(const std::string& message) {
    unsigned long pingPos = message.find("PING");
    if(pingPos != std::string::npos) {
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
    memset(&messageBuffer[0], 0, sizeof(messageBuffer));
    this->con->read(messageBuffer);
    std::cout << messageBuffer << std::endl;
    std::string stringBuffer(messageBuffer);
    if(!doPong(stringBuffer)) {
        EventDispatcher::instance()->call(new ChatEvent(stringBuffer));
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
        throw std::exception(); // close application
    }
}
