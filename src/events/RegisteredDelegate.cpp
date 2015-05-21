//
// Created by chris on 21.05.15.
//

#include "RegisteredDelegate.h"

RegisteredDelegate::RegisteredDelegate(EventHandler* owner, IDelegate *delegate) {
    this->registrar = owner->getIdentifier();
    this->delegate = delegate;
}

RegisteredDelegate::~RegisteredDelegate() {
    this->registrar.clear();
}
