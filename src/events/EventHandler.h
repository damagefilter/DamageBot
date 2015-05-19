//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_EVENTHANDLER_H
#define IRCBOT_EVENTHANDLER_H

#include "EventDispatcher.h"
#include "Delegate.h"

/**
 * Denotes an interface for handling events
 * Every object listening to events must extend from this
 */
class EventHandler {
public:
    virtual ~EventHandler() {};

protected:
//    template<LocalMethod callback>
//    Delegate* bindDelegate() {
//        return Delegate::create<TImplementation, callback>((TImplementation*)this);
//    }
};

#endif //IRCBOT_EVENTHANDLER_H
