/* 
 * File:   DamageBot.cpp
 * Author: kchristoph
 * 
 * Created on 5. Juni 2014, 13:42
 */

#include <string>
#include "DamageBot.h"

DamageBot::DamageBot(const char* _nick, const char* _user) {
    this->nick = _nick;
    this->user = _user;
    this->activeChannel = 0;
}

void DamageBot::init() {
    this->con = Connection::instance();
}

void DamageBot::doPong(std::string& message) {
    int pingPos = message.find("PING");
    if(pingPos != std::string::npos) {
        std::string pong("PONG"+message.substr(pingPos+4)+"\r\n");
        this->con->sendMessage(pong.c_str());
    }
}

void DamageBot::sendChannelMessage(std::string& message) {
    std::string toSend("PRIVMSG #"+this->activeChannel+" :"+message+"\r\n");
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


