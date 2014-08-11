/* 
 * File:   EventDispatcher.cpp
 * Author: kchristoph
 * 
 * Created on 10. Juni 2014, 14:39
 */

#include <algorithm>

#include "EventDispatcher.h"
#include "Event.h"
void EventDispatcher::registerDelegate(Delegate* delegate) {
    if (this->registeredListeners.count(delegate->getEventType()) <= 0) {
        this->registeredListeners[delegate->getEventType()] = DelegateList();
    }
    this->registeredListeners[delegate->getEventType()].push_back(delegate);
}

// TODO: In my book this should not leak memory as DelegateList is statically allocated.
// Not sure though ...
void EventDispatcher::unregisterDelegate(Delegate* delegate) {
    DelegateList vec = this->registeredListeners[delegate->getEventType()];
    // Hrmpf wtf...
    vec.erase(std::remove(vec.begin(), vec.end(), delegate), vec.end());
    this->registeredListeners[delegate->getEventType()] = vec;
}

void EventDispatcher::call(Event* event) {
    if (this->registeredListeners.count(event->getType()) <= 0) {
        return;
    }
    DelegateList relevant = registeredListeners[event->getType()];
    for (DelegateList::size_type i = 0; i < relevant.size(); ++i) {
        Delegate* d = relevant[i];
        d->call(event);
    }
}



