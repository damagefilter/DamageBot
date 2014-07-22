/* 
 * File:   StringLib.h
 * Author: kchristoph
 *
 * Created on 11. Juni 2014, 14:58
 */

#ifndef STRINGLIB_H
#define	STRINGLIB_H

#include <vector>
#include <string>
#include <sstream>
/**
 * Static class containing some string helpers
 */
class StringLib {
public:
    // String splitting from here: http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
    /**
     * Split a string by a given delmiter into a vector of strings
     * @param input
     * @param delim
     * @return 
     */
        static std::vector<std::string> split(const std::string &input, char delim) {
        std::stringstream ss(input);
        std::string item;
        std::vector<std::string> &elems;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    /**
     * Check if a string starts with the given string
     * @param input string to check
     * @param check string the input needs to start witrh
     * @return 
     */
    static bool startsWith(std::string& input, std::string& check) {
        return input.compare(0, check.length(), check) == 0;
    }
    
    static bool startsWith(std::string& input, const char* check) {
        return input.find(check) == 0;
//        return input.compare(0, strlen(check)-1, check) == 0;
    }
private:

};

#endif	/* STRINGLIB_H */

