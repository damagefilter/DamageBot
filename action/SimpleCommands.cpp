/* 
 * File:   SimpleCommands.cpp
 * Author: kchristoph
 * 
 * Created on 11. Juni 2014, 16:58
 */

#include "SimpleCommands.h"
#include "../StringLib.h"
#include "../bot/DamageBot.h"
#include <string.h>

SimpleCommands::SimpleCommands(DamageBot* _bot) {
    this->bot = _bot;
}

void SimpleCommands::execute(ChatEvent* event) {
     if (event->getSender() != this->bot->getOwner()) {
        // simple, not owner, not allowed.
        return;
    }
    std::string& message = event->getMessage();
    if (!StringLib::startsWith(message, "!")) {
        // not a command
        return;
    }
    // According to previous parse, message would start with something like "!join somethingsomething"
    std::string command = message.substr(0, message.find(" "));
    // Gimmeh dem arguments
    int splitpos = message.find(" ");
    std::string argumentString;
    // Takes away the preceeding whitespace
    if(splitpos != std::string::npos && splitpos+1 < message.size()) {
        argumentString= message.substr(splitpos+1);
    }
    else {
        argumentString= message;
    }
    
    std::vector<std::string> arguments = StringLib::split(argumentString, ' ');
    if(command == "!join" && arguments.size() >= 1) {
        std::string channel = arguments[0].substr(1);// Remove the #
        this->bot->joinChannel(channel); 
    }
    
    if(command == "!part" && arguments.size() >= 1) {
        std::string channel = arguments[0].substr(1);// Remove the #
        this->bot->partChannel(channel); 
    }
    
    if(command == "!quit") {
        if(arguments.size() >= 1) {
            this->bot->quit(argumentString, true);
        }
        else {
            this->bot->quit("Damage Bot out!", true);
        }
    }
}

