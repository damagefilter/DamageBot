//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_EVENT_H
#define IRCBOT_EVENT_H
#include <string>

class Event {
public:
    const std::string& getName() {
        return type;
    }
protected:
    std::string type;
};
#endif //IRCBOT_EVENT_H
