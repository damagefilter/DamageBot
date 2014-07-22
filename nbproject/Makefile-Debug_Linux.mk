#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug_Linux
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Connection.o \
	${OBJECTDIR}/PropertiesReader.o \
	${OBJECTDIR}/action/SimpleCommands.o \
	${OBJECTDIR}/bot/DamageBot.o \
	${OBJECTDIR}/events/EventDispatcher.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-g
CXXFLAGS=-g

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Connection.o: Connection.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Connection.o Connection.cpp

${OBJECTDIR}/PropertiesReader.o: PropertiesReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PropertiesReader.o PropertiesReader.cpp

${OBJECTDIR}/action/SimpleCommands.o: action/SimpleCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}/action
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/action/SimpleCommands.o action/SimpleCommands.cpp

${OBJECTDIR}/bot/DamageBot.o: bot/DamageBot.cpp 
	${MKDIR} -p ${OBJECTDIR}/bot
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bot/DamageBot.o bot/DamageBot.cpp

${OBJECTDIR}/events/EventDispatcher.o: events/EventDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/events
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/events/EventDispatcher.o events/EventDispatcher.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/lib/gcc/i686-redhat-linux/4.7.2/include -I/usr/local/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
