/* 
 * File:   SimpleCommands.h
 * Author: kchristoph
 *
 * Created on 11. Juni 2014, 16:58
 */

#ifndef SIMPLECOMMANDS_H
#define	SIMPLECOMMANDS_H

#include "../bot/DamageBot.h"
#include "../events/ChatEvent.h"
/**
 * Supplies the bot with a few simple commands,
 * namely join, part, quit and say
 * @param bot
 */
class SimpleCommands {
public:
    /**
     * Make new SimpleCommands object.
     * 
     * @param bot
     */
    SimpleCommands(DamageBot* _bot);
    void execute(ChatEvent* event);
private:
    DamageBot* bot;
};

#endif	/* SIMPLECOMMANDS_H */

