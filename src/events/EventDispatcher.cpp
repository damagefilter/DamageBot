/* 
 * File:   EventDispatcher.cpp
 * Author: kchristoph
 * 
 * Created on 10. Juni 2014, 14:39
 */


#include "EventDispatcher.h"
#include "Event.h"
#include "Delegate.h"

void EventDispatcher::registerDelegate(Delegate* delegate, EventType type) {
    if (this->registeredListeners.count(type) <= 0) {
        this->registeredListeners[type] = DelegateList();
    }
    this->registeredListeners[type].push_back(delegate);
}

void EventDispatcher::unregisterDelegate(Delegate* delegate, EventType type) {
    // TODO: Implement this
//    DelegateList& vec = this->registeredListeners[type];
    // Hrmpf wtf...
//    vec.remove(delegate);
}

void EventDispatcher::call(Event* event) {
    if (this->registeredListeners.count(event->getType()) <= 0) {
        return;
    }
    DelegateList& relevant = registeredListeners[event->getType()];
    for (DelegateList::size_type i = 0; i < relevant.size(); ++i) {
        relevant[i]->call(event); // calls the wrapped function
    }
}



