#
# @file - Makefile for Final Project - Space Escape
# @author - Huy Nguyen <nguyehu6@oregonstate.edu>
# @description - Simple makefile for Final Project
# @citation - Adapted from lecture videos and 
#	intermediate_make_sample (Harlan James <waldroha@oregonstate.edu>)
#

# Project name
PROJ = space_escape

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS =
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS =
#LDFLAGS += -lboost_date_time

# Valgrind options
VOPT =
VOPT += --tool=memcheck
VOPT += --leak-check=full
VOPT += --show-reachable=yes
VOPT += --show-leak-kinds=all
VOPT += --track-origins=yes

# Headers
HEADERS =
HEADERS += Menu.hpp
HEADERS += MyRandom.hpp
HEADERS += ValidateInput.hpp
HEADERS += GameDefaults.hpp
HEADERS += Inventory.hpp
HEADERS += Item.hpp
HEADERS += Game.hpp
HEADERS += Board.hpp
HEADERS += Human.hpp
HEADERS += Space.hpp
HEADERS += AsteroidObject.hpp
HEADERS += Ground.hpp
HEADERS += Rocketship.hpp
HEADERS += Crater.hpp
HEADERS += SpaceRock.hpp
HEADERS += Wormhole.hpp

# Source files
SRCS =
SRCS += main.cpp
SRCS += Menu.cpp
SRCS += MyRandom.cpp
SRCS += ValidateInput.cpp
SRCS += GameDefaults.cpp
SRCS += Inventory.cpp
SRCS += Item.cpp
SRCS += Game.cpp
SRCS += Board.cpp
SRCS += Human.cpp
SRCS += Space.cpp
SRCS += AsteroidObject.cpp
SRCS += Ground.cpp
SRCS += Rocketship.cpp
SRCS += Crater.cpp
SRCS += SpaceRock.cpp
SRCS += Wormhole.cpp

# Create an object for each source file
OBJS = $(SRCS:.cpp=.o)


# Targets
${PROJ}: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROJ}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

debug:
	@valgrind ${VOPT} ./${PROJ}

zip:
	zip Final_Project_Nguyen_Huy.zip *.hpp *.cpp *.pdf makefile -D

clean:
	rm *.o ${PROJ}
