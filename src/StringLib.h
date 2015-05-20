//
// Created by chris on 18.05.15.
//

#ifndef IRCBOT_STRINGLIB_H
#define IRCBOT_STRINGLIB_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class StringLib {
public:
    static std::vector<std::string> split(const std::string& str, const std::string&delimiter, const std::string& trim = "\r\n") {
        // from here: http://www.zedwood.com/article/106/cpp-explode-function
        // from here: http://stackoverflow.com/questions/890164/how-can-i-split-a-string-by-a-delimiter-into-an-array
        std::vector<std::string> elems;

        auto strleng = str.length();
        auto delleng = delimiter.length();
        if (delleng == 0)
            return elems;//no change

        unsigned long i = 0;
        unsigned long k = 0;
        // sure is complicated ...
        while (i < strleng) {
            int j = 0;
            while (i + j < strleng && j < delleng && str[i + j] == delimiter[j]) {
                j++;
            }
            if (j == delleng) {
                auto substring = str.substr(k, i - k);
                StringLib::trim(substring, trim);

                elems.push_back(substring);
                i += delleng;
                k = i;
            }
            else {
                i++;
            }
        }
        elems.push_back(str.substr(k, i - k));
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

    static void trim(std::string& str, const std::string& trimThis) {
        std::string::size_type pos = 0; // For storing stuff
        while ((pos = str.find(trimThis, pos)) != std::string::npos) {
            str.erase(pos, trimThis.length());
        }
    }
private:

};
#endif //IRCBOT_STRINGLIB_H
