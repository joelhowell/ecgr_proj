# Makefile for a.out
# usage: make [FLAGS=<flags>]


SOURCES 		= main.cpp utils.cpp init.cpp menu.cpp titlehelp.cpp
HEADERS 		= utils.h
TARGET  		= ../build/Battleship.exe

OBJ     		= $(patsubst %.cpp,%.o,$(SOURCES))

CXX    			= g++
GXXOPTS 		= -Wall -ansi -std=c++11 -IC:\Program\ Files\ (x86)\Windows\ Kits\10\Include\10.0.17763.0
LDLIBS  		=
CXXOPTS 		= $(GXXOPTS) $(FLAGS)
RM      		= del

all:    		$(TARGET)

# create objects (.o)
%.o:    		%.cpp $(HEADERS)
				$(CXX) $(CXXOPTS) -o $@ -c $<

# link executable
$(TARGET):		$(OBJ)
				$(CXX) $(CXXOPTS) -o $@ $^ $(LDLIBS)
				@echo "binary compiled: '$(TARGET)'"

# remove objects and executable
clean:
				$(RM) "$(TARGET)" $(OBJ)