//
// Created by chris on 21.05.15.
//

#ifndef IRCBOT_REGISTEREDDELEGATE_H
#define IRCBOT_REGISTEREDDELEGATE_H


#include <string>
#include "IDelegate.h"
#include "EventHandler.h"

class EventHandler;

class RegisteredDelegate {
private:
    std::string registrar;
    IDelegate* delegate;
public:
    RegisteredDelegate(EventHandler* owner, IDelegate* delegate);
    ~RegisteredDelegate();

    void execute(Event* event) {
        this->delegate->call(event);
    }

    std::string getRegistrar() {
        return this->registrar;
    }
};


#endif //IRCBOT_REGISTEREDDELEGATE_H
