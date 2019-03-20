# Makefile

SRC				= src
BIN				= bin
BLD				= build

SRCS			= $(wildcard $(SRC)/*.cpp) 
HEADERS			= $(wildcard $(SRC)/*.h) 
TARGET			= build/Battleship.exe

OBJ             = $(patsubst $(SRC)/%.cpp,$(BIN)/%.o,$(SRCS)) 

CXX				= g++
CXXOPTS			= -Wall -ansi -static-libgcc -static-libstdc++ -std=c++11 -IC:\Program\ Files\ (x86)\Windows\ Kits\10\Include\10.0.17763.0
RM				= del /Q

all:			$(TARGET)

# create objects
$(BIN)/%.o: $(SRC)/%.cpp     
				$(CXX) $(CXXOPTS) -o $@ -c $<

# link executable
$(TARGET):		$(OBJ)
				$(CXX) $(CXXOPTS) -o $@ $^
				@echo [INFO] bulid successful: '$(TARGET)'

# remove objects and executable
clean:
				$(RM) $(BIN) $(BLD)