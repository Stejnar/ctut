SRC=.\src
BUILD=.\build

EXE=$(BUILD)\ampel
SOURCES=$(SRC)\main.cpp
OBJECTS=$(SOURCES:$(SRC)\%.cpp=$(BUILD)\%.o)

CC=g++
CFLAGS=-g -Wall -Werror
LFLAGS=-lm

all: clean init $(EXE)

init: 
	md build

clean:
	if exist "$(BUILD)" rd /q /s $(BUILD)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)
