//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_DELEGATE_H
#define IRCBOT_DELEGATE_H

#include "Event.h"
#include "IDelegate.h"
#include <string>
#include <typeinfo>
template<typename T, typename TArgument>
class Delegate : public IDelegate {
public:
//    typedef void *Class;
//    typedef void (*Method)(Class, Event*);
    typedef void (T::*Method)(TArgument* arg);

    /**
     * Return a prepared Delegate that is bound to execute a given method,
     * on the given class instance pointer.
     * @param instance a pointer to an instance of the given class type
     * @return new Delegate object with a binding to given class and function pointer
     */
    static Delegate create(T& instance, Method method) {
        Delegate<T, TArgument> del(instance, method);
        return del;
    }

    /**
     * This method dispatches the bound function or method,
     * effectively executing what the logic within the class
     *
     * @param event
     */
    void call(Event *event) {
        (instance.*methodHandle)(static_cast<TArgument*>(event));
    }

    virtual ~Delegate() {
        methodHandle = 0;
        instance = 0;
    }

private:

    Method methodHandle;
    T& instance;
    Delegate(T& _target, Method operation) : instance(_target), methodHandle(operation) {

    }
};
#endif //IRCBOT_DELEGATE_H
