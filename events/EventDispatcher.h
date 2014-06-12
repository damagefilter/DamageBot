/* 
 * File:   EventDispatcher.h
 * Author: kchristoph
 *
 * Created on 10. Juni 2014, 14:39
 */

#ifndef EVENTDISPATCHER_H
#define	EVENTDISPATCHER_H

#include <vector>
#include <map>

#include "Event.h"
#include "../Delegate.h"

class EventDispatcher {
public:
    typedef std::vector<Delegate*> DelegateList;
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
    void registerDelegate(Delegate* delegate);
    
    /**
     * Unregister a delegate from the dispatcher.
     * After unregistering, it may be safely deleted
     * 
     * @param delegate
     */
    void unregisterDelegate(Delegate* delegate);
    
    /**
     * Invokes the call to all delegates that are listening to the event type
     * of the given event end dispatches it all.
     * @param type
     */
    void call(Event* event);
private:
    std::map<EventType, DelegateList> registeredListeners; 
};

#endif	/* EVENTDISPATCHER_H */

