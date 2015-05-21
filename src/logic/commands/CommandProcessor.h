//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_SIMPLECOMMANDS_H
#define IRCBOT_SIMPLECOMMANDS_H


#include "../../bot/IrcBot.h"
#include "../../events/ChatEvent.h"
#include "../../events/EventHandler.h"

/**
 * Dispatches a command event from incoming chat events to command handlers.
 * Consumes the chat event so there will be no further execution after a command was processed.
 */
class CommandProcessor : public EventHandler {
public:
    /**
     * Make new CommandProcessor object.
     *
     * @param bot
     */
    CommandProcessor(IrcBot* _bot);
    void handleChat(ChatEvent* event);

    virtual std::string getEventName();
    virtual std::string getIdentifier();

private:
    IrcBot* bot;
};


#endif //IRCBOT_SIMPLECOMMANDS_H
