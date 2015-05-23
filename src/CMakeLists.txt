cmake_minimum_required(VERSION 3.2)
project(IrcBot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(IrcBot ${SOURCE_FILES} networking/Connection.h tools/PropertiesFile.h tools/PropertiesFile.cpp networking/Connection.cpp bot/IrcBot.cpp bot/IrcBot.h events/Delegate.h events/Event.h events/EventHandler.h events/EventDispatcher.h events/EventDispatcher.cpp logic/commands/CommandProcessor.cpp logic/commands/CommandProcessor.h events/ChatEvent.h StringLib.h events/IDelegate.h events/RegisteredDelegate.cpp events/RegisteredDelegate.h)