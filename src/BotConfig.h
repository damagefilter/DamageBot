//
// Created by chris on 23.05.15.
//

#ifndef IRCBOT_BOTCONFIG_H
#define IRCBOT_BOTCONFIG_H


#include "tools/PropertiesFile.h"

class BotConfig {
private:
    PropertiesFile props;
protected:
    /**
     * Prepares the configuration file.
     * Makes sure it exists and is at least filled with default values.
     *
     */
    void prepare();
public:

    BotConfig();
    ~BotConfig();
    /**
     * Saves the configurations
     */
    void save();

    std::string getBotNick();

    std::string getBotUserName();

    std::string getBotOwner();

    std::string getIrcServer();

    int getIrcServerPort();

    std::string getDefaultChannel();

    static BotConfig* instance();

};


#endif //IRCBOT_BOTCONFIG_H
