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
#include "PropertiesReader.h"
#include "bot/DamageBot.h"
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
    
    bot.login(0);
    cout << "Logged in as " << props.getString("nick") << std::endl;

    cout << "Start processing messages ..." << endl;
    while(true) {
        bot.processMessage();     
    }
    return 0;
}

