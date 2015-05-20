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

typedef std::vector<IDelegate*> DelegateList;

class EventDispatcher {
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
    void registerDelegate(IDelegate* delegate, const std::string &type);

    // TODO: In all likelyhood, we have no pointer or reference to the registered delegate,
    // So there should be something like a name lookup, this requires some refactoring
//    /**
//     * Unregister a delegate from the dispatcher.
//     * After unregistering, make sure to free the memory pointed-to
//     *
//     * @param delegate
//     */
//    void unregisterDelegate(IDelegate* delegate, const std::string &type);


    void call(Event* event);
private:
    std::map<std::string, DelegateList> registeredListeners;
};

#endif //IRCBOT_EVENTDISPATCHER_H
