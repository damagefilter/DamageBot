/* 
 * File:   Event.h
 * Author: kchristoph
 *
 * Created on 10. Juni 2014, 11:59
 */

#ifndef EVENT_H
#define	EVENT_H
#include "EventType.h"
class Event {
public:
    EventType getType() {
        return type;
    }
protected:
    EventType type;
};

#endif	/* EVENT_H */

