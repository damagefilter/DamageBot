/* 
 * File:   main.cpp
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 13:41
 */

#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include "PropertiesReader.h"
#include "bot/DamageBot.h"
#include "events/EventDispatcher.h"
#include "action/SimpleCommands.h"
#include "events/EventType.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Starting Bot ..." << std::endl;
    PropertiesReader props("bot.cfg");
    DamageBot bot(props.getString("nick"), props.getString("user"), props.getString("owner"));
    bot.init();
    if(!Connection::instance()->isConnected()) {
        cout << "Connection failed, sry bro!";
        return -1;
    }
    cout << "Connected successfully" << std::endl;
    cout << "Registering events ..." << std::endl;
    SimpleCommands cmds(&bot);
    EventDispatcher::instance()->registerDelegate(
        Delegate::create<SimpleCommands, (void (SimpleCommands::*)(Event*))&SimpleCommands::execute>(&cmds, STANDARD_CHAT)
    );
    bot.login(0);
    cout << "Logged in as " << props.getString("nick") << std::endl;

    cout << "Start processing messages ..." << endl;
    try {
        while(true) {
        bot.processMessage();     
        }
    }
    catch (std::out_of_range exception) {
        cout << exception.what();
    }
    
    system("pause");
//    char derp[10];
//    cin >> derp;
    return 0;
}

