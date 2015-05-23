//
// Created by chris on 18.05.15.
//

#include <fstream>
#include <iostream>
#include <list>

#include "PropertiesFile.h"

PropertiesFile::PropertiesFile(const std::string fileName) {
    this->fileName = fileName;
    std::ifstream file(fileName);
    if (file) {
        std::string line;
        while(std::getline(file, line)) {
            auto splitPosition = line.find("="); // find first = symbol to split by
            if(splitPosition == std::string::npos) {
                continue; // Invalid format
            }
            this->data[line.substr(0, splitPosition)] = line.substr(splitPosition+1);
        }
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

int PropertiesFile::getInteger(const std::string &key, const int def) {
    if (!this->containsKey(key)) {
        this->data[key] = std::to_string(def);
        return def;
    }
    return atoi(this->data[key].c_str());
}

float PropertiesFile::getFloat(const std::string &key, const float def) {
    if (!this->containsKey(key)) {
        this->data[key] = key, std::to_string(def);
        return def;
    }
    return (float)atof(this->data[key].c_str());
}

std::string PropertiesFile::getString(const std::string &key, const std::string &def) {
    if (!this->containsKey(key)) {
        this->data[key] = def;
        return def;
    }
    return this->data[key];
}

void PropertiesFile::save() {
    std::ofstream stream;
    stream.open(this->fileName);
    if (stream.is_open()) {
        for(const auto &kvp : this->data) {
            // std::cout << it->first << ' ' << it->second << '\n';
            stream << kvp.first << "=" << kvp.second << std::endl;
        }
        stream.close();
    }
    // Throw?
}

bool PropertiesFile::fileExists(const std::string &path) {
    std::ifstream ifile(path);
    if (ifile) {
        return true;
    }
    return false;
}

bool PropertiesFile::containsKey(const std::string &key)  {
    return this->data.find(key) != data.end();
}