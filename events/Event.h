/* 
 * File:   Event.h
 * Author: kchristoph
 *
 * Created on 10. Juni 2014, 11:59
 */

#ifndef EVENT_H
#define	EVENT_H

class Event {
public:
    enum EventType {
        STANDARD_CHAT,
        PRIVATE_CHAT,
        USER_JOIN,
        USER_PART
    };
    
    EventType getType() {
        return type;
    }
protected:
    EventType type;
};

#endif	/* EVENT_H */

