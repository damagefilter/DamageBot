/* 
 * File:   PropertiesReader.cpp
 * Author: kchristoph
 * 
 * Created on 6. Juni 2014, 13:01
 */

#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>

#include "PropertiesReader.h"

PropertiesReader::PropertiesReader(const char* fileName) {
    std::ifstream file(fileName);
    std::string line;
    while(std::getline(file, line)) {
        int splitPosition = line.find("="); // find first = symbol to split by
        if(splitPosition == std::string::npos) {
            continue; // Invalid format
        }
        this->data[line.substr(0, splitPosition)] = line.substr(splitPosition+1);
    }
}

int PropertiesReader::getInteger(const char* key) {
    if(!containsKey(key)) {
        return 0;
    }
    return atoi(this->data[key].c_str());
}

float PropertiesReader::getFloat(const char* key) {
    if(!containsKey(key)) {
        return 0.0f;
    }
    return atof(this->data[key].c_str());
}

const char* PropertiesReader::getString(const char* key) {
    if(!containsKey(key)) {
        return "key not found";
    }
    return this->data[key].c_str();
}

