//
// Created by chris on 18.05.15.
//

#include <fstream>
#include <iostream>
#include <list>

#include "PropertiesFile.h"

PropertiesFile::PropertiesFile(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string line;
    while(std::getline(file, line)) {
        auto splitPosition = line.find("="); // find first = symbol to split by
        if(splitPosition == std::string::npos) {
            continue; // Invalid format
        }
        this->data[line.substr(0, splitPosition)] = line.substr(splitPosition+1);
    }
}

int PropertiesFile::getInteger(const std::string &key) {
    if(!containsKey(key)) {
        return 0;
    }
    return atoi(this->data[key].c_str());
}

float PropertiesFile::getFloat(const std::string &key) {
    if(!containsKey(key)) {
        return 0.0f;
    }
    return (float)atof(this->data[key].c_str());
}

std::string PropertiesFile::getString(const std::string &key) {
    if(!containsKey(key)) {
        return "key not found";
    }
    return this->data[key].c_str();
}