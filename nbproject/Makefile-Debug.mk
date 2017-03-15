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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main_client.o \
	${OBJECTDIR}/main_server.o \
	${OBJECTDIR}/src/DrawServiceImpl.o \
	${OBJECTDIR}/src/PetitPrinceServiceImpl.o \
	${OBJECTDIR}/src/ServiceDraw_DynStub.o \
	${OBJECTDIR}/src/ServiceDraw_Stub.o


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
LDLIBSOPTIONS=`pkg-config --libs omniCOS4` `pkg-config --libs omniCOSDynamic4` `pkg-config --libs omniConnectionMgmt4` `pkg-config --libs omniDynamic4` `pkg-config --libs omniEvents` `pkg-config --libs omniORB4` `pkg-config --libs omnithread3`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/petitprince

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/petitprince: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/petitprince ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main_client.o: main_client.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_client.o main_client.cpp

${OBJECTDIR}/main_server.o: main_server.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_server.o main_server.cpp

${OBJECTDIR}/src/DrawServiceImpl.o: src/DrawServiceImpl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DrawServiceImpl.o src/DrawServiceImpl.cpp

${OBJECTDIR}/src/PetitPrinceServiceImpl.o: src/PetitPrinceServiceImpl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/PetitPrinceServiceImpl.o src/PetitPrinceServiceImpl.cpp

${OBJECTDIR}/src/ServiceDraw_DynStub.o: src/ServiceDraw_DynStub.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServiceDraw_DynStub.o src/ServiceDraw_DynStub.cpp

${OBJECTDIR}/src/ServiceDraw_Stub.o: src/ServiceDraw_Stub.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ihdr `pkg-config --cflags omniCOS4` `pkg-config --cflags omniCOSDynamic4` `pkg-config --cflags omniConnectionMgmt4` `pkg-config --cflags omniDynamic4` `pkg-config --cflags omniEvents` `pkg-config --cflags omniORB4` `pkg-config --cflags omnithread3` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServiceDraw_Stub.o src/ServiceDraw_Stub.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/petitprince

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
