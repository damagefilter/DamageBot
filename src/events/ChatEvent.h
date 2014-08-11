/* 
 * File:   ChatEvent.h
 * Author: kchristoph
 *
 * Created on 11. Juni 2014, 14:13
 */

#ifndef CHATEVENT_H
#define	CHATEVENT_H

#include "Event.h"
#include "../tools/StringLib.h"
#include <string>

class ChatEvent : public Event {
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
        this->type = STANDARD_CHAT;
    }
    
    /**
     * Get the sender of this message
     * @return the sender
     */
    std::string& getSender() {
        return this->sender;
    }
    
    /**
     * Get the host the message sender sits on
     * @return the host
     */
    std::string& getHost() {
        return this->host;
    }
    
    /**
     * Get the message that was sent.
     * Depending on command, this may be a list
     * of space separated command arguments.
     * @return 
     */
    std::string& getMessage() {
        return this->message;
    }
    
    /**
     * Get the command that was issued with this message
     * @return 
     */
    std::string& getCommand() {
        return this->command;
    }
    
    /**
     * Get the recipient of this message.
     * This can be a username or a channel name.
     * With isChannelChat you can find out
     * @return 
     */
    std::string& getRecipient() {
        return this->recipient;
    }
    
    /**
     * Whether this message is directed at a channel or not.
     * If not, this is a private message
     * @return 
     */
    bool isChannelChat() {
        return !this->isPrivateChat;
    }
    
private:
    std::string sender;
    std::string host;
    std::string message;
    std::string command;
    std::string recipient;
    bool isPrivateChat; // This it is when the receiver does not start with # (is not a channel)
    
    // TODO: Move this into an IRCHelper class or something.
    // Too generic to have it in here
    void parseInput(std::string buffer) {
        int prefixEnd = -1, trailingStarts = buffer.length();
        std::string _prefix = "\0";
        std::string _trailing = "\0";
        std::string _command = "\0";
        std::string _message = "\0";
        // Grab the prefix if it is present. If a message begins
        // with a colon, the characters following the colon until
        // the first space are the prefix.
        // Compare if a match from 0 to 1 element occurs with the given string (":")
        
        if(StringLib::startsWith(buffer, ":")) {
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
            std::vector<std::string> senderAndHost = StringLib::split(_prefix, '!'); 
            this->sender = senderAndHost[0]; // First element is username according to format user!user@host
            if(senderAndHost.size() > 1) {
                int splitPos = senderAndHost[1].find("@");
                if(splitPos != std::string::npos) {
                    this->host = senderAndHost[1].substr(splitPos); // After the @ comes the host
                }
                else {
                    this->host = senderAndHost[1];
                }
            }
            else {
                this->host = this->sender;
            }
            
        }
        
        std::vector<std::string> cmdAndParams = StringLib::split(buffer.substr(prefixEnd + 1, trailingStart - prefixEnd - 1), ' ');
        _command = cmdAndParams[0];
        if(cmdAndParams.size() > 1) {
            int nameSpacer = _message.find(" ");
            if(nameSpacer != std::string::npos) {
                _message = cmdAndParams[1].substr(nameSpacer);
            // First spaceless part is the name to which this message goes to
            std::string _recipient = _message.substr(0, nameSpacer);
            this->recipient = _recipient;
            }
            
            if(StringLib::startsWith(recipient, "#")) {
                this->isPrivateChat = false;
            }
            else {
                this->isPrivateChat = true;
            }
            
            
        }
        if(_trailing != "\0") {
            _message.append(_trailing);
        }
        this->message = _message;
        this->command = _command;
        
    }
};

#endif	/* CHATEVENT_H */

