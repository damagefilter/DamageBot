//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_EVENTDISPATCHER_H
#define IRCBOT_EVENTDISPATCHER_H

#include <vector>
#include <map>
#include <functional>

#include "Event.h"
#include "EventHandler.h"
#include "Delegate.h"
#include "RegisteredDelegate.h"

class RegisteredDelegate;
class EventHandler;

typedef std::vector<RegisteredDelegate*> DelegateList;
class EventDispatcher {
private:
    std::map<std::string, DelegateList> registeredListeners;

public:
    static EventDispatcher* instance() {
        static EventDispatcher* $ = new EventDispatcher();
        return $;
    }

    /**
     * Register a delegate to the event dispatcher,
     * this will then receive messages from the bot.
     *
     * @param delegate the delegate to register
     */
    void registerDelegate(EventHandler *handler, IDelegate *delegate);

    /**
     * Unregister all delegates of the given event handler and event type.
     */
    void unregisterDelegate(EventHandler* handler, const std::string &type);

    /**
     * Unregister ALL delegates of the given event handler.
     */
    void unregisterDelegate(EventHandler* handler);


    void call(Event* event);
};

#endif //IRCBOT_EVENTDISPATCHER_H
