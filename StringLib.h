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
    static std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
private:
    static std::vector<std::string> &split(const std::string &input, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(input);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};

#endif	/* STRINGLIB_H */

