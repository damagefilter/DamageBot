/* 
 * File:   DamageBot.cpp
 * Author: kchristoph
 * 
 * Created on 5. Juni 2014, 13:42
 */

#include <string>
#include <iostream>
#include "DamageBot.h"

DamageBot::DamageBot(const char* _nick, const char* _user, const char* _owner) {
    this->nick = _nick;
    this->user = _user;
    this->owner = _owner;
//    this->activeChannel;
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

void DamageBot::login(const char* password) {
    std::string buf;
    buf.append("NICK ").append(this->nick).append("\r\n");
    this->con->sendMessage(buf.c_str());
    buf.clear();
    
    buf.append("USER ").append(this->nick).append(" 0 * :").append(this->user).append("\r\n");
    this->con->sendMessage(buf.c_str());
    buf.clear();
    if (password != 0) {
        buf.append("PRIVMSG NickServ IDENTIFY ").append(password).append("\r\n");
        this->con->sendMessage(buf.c_str());
        buf.clear();
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

void DamageBot::processMessage() {
    // Empty the string
    memset(&messageBuffer[0], 0, sizeof(messageBuffer));
    this->con->read(messageBuffer);
    std::cout << messageBuffer << std::endl;
    std::string stringBuffer(messageBuffer);
    doPong(stringBuffer);
}



void DamageBot::joinChannel(std::string& channel) {
    std::string toSend("JOIN #"+channel+"\r\n");
    this->con->sendMessage(toSend.c_str());
}

void DamageBot::partChannel(std::string& channel) {
    std::string toSend("PART #"+channel+"\r\n");
    this->con->sendMessage(toSend.c_str());
}


