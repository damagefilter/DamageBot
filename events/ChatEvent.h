/* 
 * File:   ChatEvent.h
 * Author: kchristoph
 *
 * Created on 11. Juni 2014, 14:13
 */

#ifndef CHATEVENT_H
#define	CHATEVENT_H

#include "Event.h"
#include "../StringLib.h"
#include <string>

class ChatEvent : private Event {
public:
    
    /**
     * Creates a new chat event object that will parse the message and
     * correpsonding meta data from the server input.
     * This will handle only PRIVMSG messages
     * You may then use this to dispatch the data to event handlers of all sorts
     * 
     * @param messageBuffer the incoming message
     */
    ChatEvent(char* messageBuffer) {
        parseInput(std::string(messageBuffer));
        this->type = Event::EventType::STANDARD_CHAT;
    }
    
    std::string* getUser() {
        return &this->user;
    }
    
    std::string* getHost() {
        return &this->host;
    }
    
    std::string* getMessage() {
        return &this->command;
    }
private:
    std::string user;
    std::string host;
    std::string message;
    std::string command;
    bool isPrivateChat; // This it is when the receiver does not start with # (is not a channel)
    
    // TODO: Move this into an IRCHelper class or something.
    // Too generic to have it in here
    void parseInput(std::string buffer) {
        int prefixEnd = buffer.length();
        std::string _prefix = "\0";
        std::string _trailing = "\0";
        std::string _command = "\0";
        std::string _message = "\0";
        // Grab the prefix if it is present. If a message begins
        // with a colon, the characters following the colon until
        // the first space are the prefix.
        // Compare if a match from 0 to 1 element occurs with the given string (":")
        if(buffer.compare(0, 1, ":") == 0) {
            prefixEnd = buffer.find(" ");
            _prefix = buffer.substr(1, prefixEnd - 1);
        }
        
        // Grab the trailing if it is present. If a message contains
        // a space immediately following a colon, all characters after
        // the colon are the trailing part.
        int trailingStart = buffer.find(" :");
        if(trailingStart != std::string::npos) {
            _trailing = buffer.substr(trailingStart + 2);
        }
        else {
            trailingStart = buffer.length();
        }
        
        if(_prefix != "\0") {
            // This should always be set but according to IRC protocol, this appears to be optional ... hu
            std::vector<std::string> userAndHost = StringLib::split(_prefix, "!"); 
            this->user = userAndHost[0]; // First element is udername according to format user!user@host
            this->host = userAndHost[1].substr(userAndHost[1].find("@")); // After the @ comes the host
        }
        
        std::vector<std::string> cmdAndParams = StringLib::split(buffer.substr(prefixEnd + 1, trailingStart - prefixEnd - 1), " ");
        _command = cmdAndParams[0];
        if(cmdAndParams.size() > 1) {
            _message = cmdAndParams[1];
        }
        if(_trailing != "\0") {
            _message.append(" ").append(_trailing);
        }
        this->message = _message;
        this->command = _command;
        
    }
};

#endif	/* CHATEVENT_H */

