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
CND_PLATFORM=MinGW_1-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/bot/DamageBot.o \
	${OBJECTDIR}/src/events/EventDispatcher.o \
	${OBJECTDIR}/src/logic/simplecommands/SimpleCommands.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/networking/Connection.o \
	${OBJECTDIR}/src/tools/PropertiesReader.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/bot/DamageBot.o: src/bot/DamageBot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/bot
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bot/DamageBot.o src/bot/DamageBot.cpp

${OBJECTDIR}/src/events/EventDispatcher.o: src/events/EventDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/events
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/events/EventDispatcher.o src/events/EventDispatcher.cpp

${OBJECTDIR}/src/logic/simplecommands/SimpleCommands.o: src/logic/simplecommands/SimpleCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/logic/simplecommands
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/logic/simplecommands/SimpleCommands.o src/logic/simplecommands/SimpleCommands.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/networking/Connection.o: src/networking/Connection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/networking
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/networking/Connection.o src/networking/Connection.cpp

${OBJECTDIR}/src/tools/PropertiesReader.o: src/tools/PropertiesReader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tools/PropertiesReader.o src/tools/PropertiesReader.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/damagebot.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
