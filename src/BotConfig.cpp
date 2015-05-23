//
// Created by chris on 23.05.15.
//

#include "BotConfig.h"


BotConfig* BotConfig::instance() {
    static BotConfig* $ = new BotConfig();
    return $;
}

BotConfig::BotConfig() : props("bot.cfg") {
    prepare();
}

BotConfig::~BotConfig() {
    props.save();
}

void BotConfig::save() {
    props.save();
}

std::string BotConfig::getBotNick() {
    return props.getString("nick", "DamageBot");
}

std::string BotConfig::getBotUserName() {
    return props.getString("user", "DamageBot");
}

std::string BotConfig::getBotOwner() {
    return props.getString("owner", "the_owner");
}

std::string BotConfig::getIrcServer() {
    return props.getString("host", "irc.freenode.net");
}

int BotConfig::getIrcServerPort() {
    return props.getInteger("port", 6667);
}

std::string BotConfig::getDefaultChannel() {
    return props.getString("defaultChannel", "some_channel");
}

void BotConfig::prepare() {
    if (!PropertiesFile::fileExists("bot.cfg")) {
        getBotNick();
        getBotUserName();
        getBotOwner();
        getIrcServer();
        getIrcServerPort();
        getDefaultChannel();
        save();
    }
}
