/* 
 * File:   ChatbotHandler.cpp
 * Author: kchristoph
 * 
 * Created on 20. August 2014, 15:34
 */

#include "ChatbotHandler.h"
#include "../../events/EventType.h"
ChatbotHandler::ChatbotHandler() {
    EventDispatcher::instance()->registerDelegate(
            this->bindDelegate<(LocalMethod)&ChatbotHandler::handleChat>(), STANDARD_CHAT);
}

void ChatbotHandler::handleChat(ChatEvent* chat) {
    // do something
}

