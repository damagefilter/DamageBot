/* 
 * File:   IniReader.h
 * Author: kchristoph
 * Taken from http://www.codeproject.com/Articles/10809/A-Small-Class-to-Read-INI-File
 * Might aswell include the writer and combine into one class some day
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
private:
    std::map<std::string, std::string> data;
    
    bool containsKey(const char* key) {
        return this->data.find(key) != data.end();
    }
};

#endif	/* INIREADER_H */

