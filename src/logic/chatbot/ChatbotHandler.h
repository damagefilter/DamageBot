/* 
 * File:   ChatbotHandler.h
 * Author: kchristoph
 *
 * Created on 20. August 2014, 15:34
 */

#ifndef CHATBOTHANDLER_H
#define	CHATBOTHANDLER_H
#include "../../events/ChatEvent.h"
#include "../../events/EventHandler.h"
class ChatbotHandler : public EventHandler<ChatbotHandler> {
public:
    ChatbotHandler();    
    void handleChat(ChatEvent* chat);
private:

};

#endif	/* CHATBOTHANDLER_H */

