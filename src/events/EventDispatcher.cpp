//
// Created by chris on 18.05.15.
//

#include "EventDispatcher.h"
#include <algorithm> // for std::find

void EventDispatcher::registerDelegate(EventHandler *handler, IDelegate *delegate) {
    auto type = handler->getEventName();
    if (this->registeredListeners.count(type) <= 0) {
        this->registeredListeners[type] = DelegateList();
    }
    this->registeredListeners[type].push_back(new RegisteredDelegate(handler, delegate));
}

void EventDispatcher::unregisterDelegate(EventHandler *handler, const std::string &type) {
    DelegateList& vec = this->registeredListeners[type];
    DelegateList::iterator it = vec.begin();

    while (it != vec.end()) {
        if ((*it)->getRegistrar() == handler->getIdentifier()) {
            it = vec.erase(it);
        }
        else {
            it++;
        }
    }
    if (vec.size() <= 0) {
        this->registeredListeners.erase(type);
    }
}


void EventDispatcher::unregisterDelegate(EventHandler *handler) {
    throw std::exception();
}

void EventDispatcher::call(Event* event) {
    if (this->registeredListeners.count(event->getName()) <= 0) {
        return;
    }
    DelegateList& relevant = registeredListeners[event->getName()];
    for (DelegateList::size_type i = 0; i < relevant.size(); ++i) {
        relevant[i]->execute(event);
    }
}