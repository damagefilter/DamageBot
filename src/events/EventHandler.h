/* 
 * File:   EventHandler.h
 * Author: kchristoph
 *
 * Created on 20. August 2014, 13:32
 */

#ifndef EVENTHANDLER_H
#define	EVENTHANDLER_H
#include "EventDispatcher.h"
#include "Delegate.h"
/**
 * Denotes an interface for handling events
 * Every object listening to events must extend from this
 */
template<typename TImplementation>
class EventHandler {
public:
    typedef void (TImplementation::*LocalMethod)(Event*);
    virtual ~EventHandler() {};
    
protected:
    template<LocalMethod callback>
    Delegate* bindDelegate() {
        return Delegate::create<TImplementation, callback>((TImplementation*)this);
    }
};

#endif	/* EVENTHANDLER_H */