//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_SIMPLECOMMANDS_H
#define IRCBOT_SIMPLECOMMANDS_H


#include "../bot/IrcBot.h"
#include "../events/ChatEvent.h"
#include "../events/EventHandler.h"
/**
 * Supplies the bot with a few simple commands,
 * namely join, part, quit and say
 */
class SimpleCommands : public EventHandler {
public:
    /**
     * Make new SimpleCommands object.
     *
     * @param bot
     */
    SimpleCommands(IrcBot* _bot);
    void handleChat(ChatEvent* event);

    std::string getEventName() {
        return ChatEvent().getName();
    }

private:
    IrcBot* bot;
};


#endif //IRCBOT_SIMPLECOMMANDS_H
