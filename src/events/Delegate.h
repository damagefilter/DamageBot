/* 
 * File:   Delegate.h
 * Author: kchristoph
 *
 * Dispatches Events and notifies listening objects
 * Created on 17. September 2013, 11:19
 * Taken and modified from http://www.theorangeday.com/tutorials/c-event-system-using-delegates/
 */

#ifndef DELEGATE_H
#define	DELEGATE_H

#include "Event.h"
#include "EventType.h"
#include <string>
#include <typeinfo>

class Delegate {
public:
    typedef void *Class;
    typedef void (*Method)(Class, Event*);
    
    /**
     * Return a prepared Delegate that is bound to execute a given method,
     * on the given class instance pointer.
     * @param instance a pointer to an instance of the given class type
     * @return new Delegate object with a binding to given class and function pointer
     */
    template <class T, void (T::*ExMethod)(Event*)>
    static Delegate* create(T* instance) {
        Delegate* del = new Delegate();
//        del->bind<C, ExMethod>(instance, type);
        del->instance = instance;
        del->methodHandle = &classMethodDelegator<T, ExMethod>;
        return del;
    }
    
    /**
     * This method dispatches the bound function or method,
     * effectively executing what the logic within the class
     * 
     * @param event
     */
    void call(Event *event) {
        return methodHandle(instance, event);
    }
    
    virtual ~Delegate() {
        methodHandle = 0;
        instance = 0;
    }
    
private:
    Method methodHandle;
    Class instance;

    /**
     * Delegates a method of a class.
     * This will crash epicly if the class doesn't contain said method!
     * 
     * @param cls the class object
     * @param event the event to pass
     */
    
    template <class T, void (T::*Function)(Event*)>
    static inline void classMethodDelegator(Class instance, Event* arg) {
        return (static_cast<T*>(instance)->*Function)(arg);
    }
};

#endif	/* DELEGATE_H */

