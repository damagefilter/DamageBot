/* 
 * File:   PropertiesReader.h
 * Author: kchristoph
 * Created on 6. Juni 2014, 13:01
 */

#ifndef INIREADER_H
#define	INIREADER_H

#include <string>
#include <map>

class PropertiesReader {
public:
    PropertiesReader(const char* filename);
    
    int getInteger(const char* key);
    float getFloat(const char* key);
//    bool getBoolean(char* key);
    const char* getString(const char* key);
    
    bool containsKey(const char* key) {
        return this->data.find(key) != data.end();
    }
private:
    std::map<std::string, std::string> data;
};

#endif	/* INIREADER_H */

