//
// Created by chris on 18.05.15.
//

#include "EventDispatcher.h"
#include <algorithm> // for std::find

void EventDispatcher::registerDelegate(IDelegate* delegate, const std::string &type) {
    if (this->registeredListeners.count(type) <= 0) {
        this->registeredListeners[type] = DelegateList();
    }
    this->registeredListeners[type].push_back(delegate);
}

void EventDispatcher::unregisterDelegate(IDelegate* delegate, const std::string &type) {
    DelegateList& vec = this->registeredListeners[type];
    // ya know, could just add indexOf to vectors and such ...
    auto it = std::find(vec.begin(), vec.end(), delegate);
    if (it != vec.end()) {
        vec.erase(it);
    }
    if (vec.size() <= 0) {
        this->registeredListeners.erase(type);
        // supposedly vec doesn't need deleting as it's only a reference which is kept by the listener map.
    }
}

void EventDispatcher::call(Event* event) {
    if (this->registeredListeners.count(event->getName()) <= 0) {
        return;
    }
    DelegateList& relevant = registeredListeners[event->getName()];
    for (DelegateList::size_type i = 0; i < relevant.size(); ++i) {
        relevant[i]->call(event);
    }
}