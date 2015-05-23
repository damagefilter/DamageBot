#include <cstdlib>
#include <map>
#include <iostream>
#include "tools/PropertiesFile.h"
#include "bot/IrcBot.h"
#include "logic/commands/CommandProcessor.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Starting Bot ..." << endl;
    PropertiesFile props("bot.cfg");
    IrcBot bot(props.getString("nick"), props.getString("user"), props.getString("owner"));
    if(!bot.init()) {
        cout << "Connection failed, sry bro!";
        return 1;
    }
    cout << "Connected successfully" << endl;
    cout << "Registering events ..." << endl;
    bot.addHandler<CommandProcessor, ChatEvent>(new CommandProcessor(&bot), &CommandProcessor::handleChat);
    bot.login(props.getString("defaultChannel"), "");
    cout << "Logged in as " << props.getString("nick") << endl;

    cout << "Start processing messages ..." << endl;
    try {
        while(true) {
            bot.processMessage();
        }
    }
    catch (out_of_range exception) {
        cout << exception.what();
    }
    return 0;
}