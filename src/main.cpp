#include <cstdlib>
#include <map>
#include <iostream>
#include "bot/IrcBot.h"
#include "logic/commands/CommandProcessor.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Starting Bot ..." << endl;
    BotConfig* cfg = BotConfig::instance();
    IrcBot bot(cfg->getBotNick(), cfg->getBotUserName(), cfg->getBotOwner());
    if(!bot.init()) {
        cout << "Connection failed, sry bro!";
        return 1;
    }
    cout << "Connected successfully" << endl;
    cout << "Registering events ..." << endl;
    bot.addHandler<CommandProcessor, ChatEvent>(new CommandProcessor(&bot), &CommandProcessor::handleChat);
    bot.login(cfg->getDefaultChannel(), "");
    cout << "Logged in as " << cfg->getBotNick() << endl;

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