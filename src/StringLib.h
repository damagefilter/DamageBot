//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_STRINGLIB_H
#define IRCBOT_STRINGLIB_H

#include <vector>
#include <string>
#include <sstream>

class StringLib {
public:
    // String splitting from here: http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
    /**
     * Split a string by a given delmiter into a vector of strings
     * @param input
     * @param delim
     * @return
     * TODO: Find a way to split strings by tokens
     */
    static std::vector<std::string> split(const std::string &input, char delim) {
        std::stringstream ss(input);
        std::string item;
        std::vector<std::string> elems;
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
    static bool startsWith(const std::string& input, const std::string& check) {
        return input.find(check) == 0;
//        return input.compare(0, strlen(check)-1, check) == 0;
    }
private:

};
#endif //IRCBOT_STRINGLIB_H
