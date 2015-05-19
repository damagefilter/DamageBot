//
// Created by chris on 19.05.15.
//

#ifndef IRCBOT_IDELEGATE_H
#define IRCBOT_IDELEGATE_H

#include "Event.h"

class IDelegate {
public:
    virtual void call(Event* event) = 0;
};
#endif //IRCBOT_IDELEGATE_H
