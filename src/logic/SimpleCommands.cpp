//
// Created by chris on 18.05.15.
//

#include "SimpleCommands.h"

SimpleCommands::SimpleCommands(IrcBot* _bot) {
    this->bot = _bot;
    auto delegate = Delegate<SimpleCommands, ChatEvent>::create(*this, &SimpleCommands::handleChat);
    EventDispatcher::instance()->registerDelegate(delegate, ChatEvent().getName());
}

void SimpleCommands::handleChat(ChatEvent* event) {
    if (event->getSender() != this->bot->getOwner()) {
        // simple, not owner, not allowed.
        return;
    }
    std::string& message = event->getMessage();
    if (!StringLib::startsWith(message, "!")) {
        // not a command
        return;
    }
    if (event->isChannelChat()) {
        this->bot->setActiveChannel(event->getRecipient().substr(1));
    }
    // message would start with something like "!join somethingsomething"
    std::string command = message.substr(0, message.find(" "));
    // Gimmeh dem arguments
    unsigned long splitpos = message.find(" ");
    std::string argumentString;
    // Takes away the preceeding whitespace
    if(splitpos != std::string::npos && splitpos+1 < message.size()) {
        argumentString = message.substr(splitpos+1);
    }
    else {
        argumentString = message;
    }
    StringLib::trim(argumentString, "\r\n");
    std::vector<std::string> arguments = StringLib::split(argumentString, " ");
    if(command == "!join" && arguments.size() >= 1) {
        std::string channel = arguments[0].substr(1);// Remove the #
        StringLib::trim(channel, "\r\n");
        this->bot->joinChannel(channel);
    }

    if(command == "!part" && arguments.size() >= 1) {
        std::string channel = arguments[0].substr(1);// Remove the #
        StringLib::trim(channel, "\r\n");
        this->bot->partChannel(channel);
    }

    if(command == "!say") {
        if(arguments.size() >= 1) {
            this->bot->sendChannelMessage(argumentString);
        }
        else {
            this->bot->sendChannelMessage("Argument size is smaller 1. Argument String is: " + argumentString);
        }
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