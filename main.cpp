/* 
 * File:   main.cpp
 * Author: kchristoph
 *
 * Created on 5. Juni 2014, 13:41
 */

#include <cstdlib>
#include <map>
#include <string>
#include <iostream>
#include "PropertiesReader.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    PropertiesReader reader("bot.cfg");
    cout << reader.getString("nick") << endl;
    cout << reader.getString("knick") << endl;
    cout << "Hello world" << endl;
    char derp[255];
    cin >> derp;
    return 0;
}

