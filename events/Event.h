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
    Event();
    Event(const Event& orig);
    virtual ~Event();
    enum EventType {
        STANDARD_CHAT,
        USER_JOIN,
        USER_PART
    };
private:
    EventType type;
};

#endif	/* EVENT_H */

