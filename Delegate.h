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

#include "events/Event.h"
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
    template <class C, void (C::*Method)(Event*)>
    static Delegate* create(C *instance, Event::EventType type) {
        Delegate* del = new Delegate();
        del->bind<C, Method>(instance, type);
        return del;
    }
    
    /**
     * This method dispatches the bound function or method,
     * effectively executing what the logic within the class
     * 
     * @param event
     */
    void call(Event *event) {
        return methodHandle(classHandle, event);
    }
    
    Event::EventType getEventType() {
        return eventType;
    }
    
    virtual ~Delegate() {}
    
private:
    Method methodHandle;
    Class classHandle;
    Event::EventType eventType;
    
    /**
     * Delegates a global method.
     * 
     * @param 
     *      makeitUniform unused, just to have a uniform method call 
     *      from event handling
     * @param event
     */
    template <void (*Method)(Event*)>
    static void methodDelegator(Class makeItUniform, Event *event) {
        return (Method) (event);
    }

    /**
     * Delegates a method of a class.
     * This will crash epicly if the class doesn't contain said method!
     * 
     * @param cls the class object
     * @param event the event to pass
     */
    template <class C, void (C::*Method)(Event*)>
    static void classMethodDelegator(Class cls, Event *event) {
        return (static_cast<C*> (cls)->*Method)(event);
    }
    
//    void getTypeFromEvent
    
    /**
     * Bind a function to this Delegate.
     * @template function to execute, Event class
     */
    template <void (*Method)(Event*), class E>
    void bind(Event::EventType type) {
        classHandle = 0;
        methodHandle = &methodDelegator<Method>;
        eventType = type;
    }
    
    /**
     * Bind a method tho this delegate to a specified class.
     * 
     * @param cls the class object
     * @template Listener class, Event class, Listener method
     */
    template <class C, class E, void (C::*Method)(Event*)>
    void bind(C *cls, Event::EventType eType) {
        methodHandle = &classMethodDelegator<C, Method>;
        classHandle = cls;
        eventType = eType;
    }
};

#endif	/* DELEGATE_H */

