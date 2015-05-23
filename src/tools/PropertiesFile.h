//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_PROPERTIESREADER_H
#define IRCBOT_PROPERTIESREADER_H

#include <string>
#include <map>

class PropertiesFile {
private:
    std::map<std::string, std::string> data;
    std::string fileName;

public:
    PropertiesFile(const std::string filename);

    int getInteger(const std::string &key);

    int getInteger(const std::string &key, const int def);

    float getFloat(const std::string &key);

    float getFloat(const std::string &key, const float def);

    std::string getString(const std::string &key);

    std::string getString(const std::string &key, const std::string &def);

    bool containsKey(const std::string &key);

    void save();

    static bool fileExists(const std::string &path);
};

#endif //IRCBOT_PROPERTIESREADER_H
