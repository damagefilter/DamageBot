/* 
 * File:   DamageBot.cpp
 * Author: kchristoph
 * 
 * Created on 5. Juni 2014, 13:42
 */

#include <string>
#include "DamageBot.h"

DamageBot::DamageBot(char* _nick, char* _user, char* _host, int _port) {
    this->nick = _nick;
    this->user = _user;
    this->host = _host;
    this->port = _port;
}

void DamageBot::init() {
    this->con = new Connection(this->host, this->port);
    if(this->con->makeConnection() == -1) {
        // TODO: Should ne somethign mroe graceful right there...
        // NOTE: If error occured, makeConnection already mentioned it to stderr
        exit(-1); // FAIL
    }
}

void DamageBot::doPong(std::string& message) {
    size_t pingPos = message.find("PING");
    if(pingPos != std::string::npos) {
        std::string pong("PONG"+message.substr(pingPos+4)+"\r\n");
        this->con->sendMessage(pong.c_str());
    }
}

void DamageBot::sendChannelMessage(std::string& message) {
    std::string toSend("PRIVMSG #channel :"+message+"\r\n");
    this->con->sendMessage(toSend.c_str());
}

void DamageBot::sendPrivateMessage(std::string& message, std::string& user) {
    std::string toSend("PRIVMSG "+user+" :"+message+"\r\n");
    this->con->sendMessage(toSend.c_str());
}


void DamageBot::joinChannel(std::string& channel) {
    std::string toSend("JOIN #"+channel+"\r\n");
    this->con->sendMessage(toSend.c_str());
}

void DamageBot::partChannel(std::string& channel) {
    std::string toSend("PART #"+channel+"\r\n");
    this->con->sendMessage(toSend.c_str());
}


