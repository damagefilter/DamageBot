//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_CHATEVENT_H
#define IRCBOT_CHATEVENT_H
#include "Event.h"
#include "../StringLib.h"
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
    ChatEvent(const std::string &messageBuffer) {
        this->type = "standard_chat";
        parseInput(messageBuffer);
    }

    ChatEvent() {
        this->type = "standard_chat";
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
    void parseInput(const std::string &buffer) {
        unsigned long prefixEnd = 0;
        std::string _prefix = "\0";
        std::string message = "\0";
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
        // the colon are the message part.
        unsigned long messageStart = buffer.find(" :");
        if(messageStart != std::string::npos) {
            message = buffer.substr(messageStart + 2);
        }
        else {
            messageStart = buffer.length();
        }

        if(_prefix.length() > 0) {
            // There are messages where the prefix does not contain the ! meaning there is no user that sent it
            // Possibly system message
            if (_prefix.find("!") != std::string::npos) {
                std::vector<std::string>& senderAndHost = *StringLib::split(_prefix, "!");
                this->sender = senderAndHost[0]; // First element is username according to format user!user@host
                if(senderAndHost.size() > 1) {
                    size_t splitPos = senderAndHost[1].find("@");
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
            else {
                this->sender = _prefix;
                this->host = _prefix;
            }
        }

        std::vector<std::string>& cmdAndParams = *StringLib::split(buffer.substr(prefixEnd + 1, messageStart), " ");
        _command = cmdAndParams[0];
        if(cmdAndParams.size() > 1) {
            this->recipient = cmdAndParams[1];
            std::cout << this->recipient << std::endl;
            this->isPrivateChat = !StringLib::startsWith(recipient, "#");
        }
        if(message != "\0") {
            _message.append(message);
        }
        this->message = _message;
        this->command = _command;

    }
};
#endif //IRCBOT_CHATEVENT_H
