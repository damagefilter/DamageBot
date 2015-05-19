//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_PROPERTIESREADER_H
#define IRCBOT_PROPERTIESREADER_H

#include <string>
#include <map>

class PropertiesReader {
public:
    PropertiesReader(const std::string &filename);

    int getInteger(const std::string &key);
    float getFloat(const std::string &key);
    std::string getString(const std::string &key);

    bool containsKey(const std::string &key) {
        return this->data.find(key) != data.end();
    }
private:
    std::map<std::string, std::string> data;
};

#endif //IRCBOT_PROPERTIESREADER_H
