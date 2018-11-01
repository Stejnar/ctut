SRC=.\src
BUILD=.

EXE=$(BUILD)\snake.exe
SOURCES=$(SRC)\main.cpp
OBJECTS=$(SOURCES:$(SRC)\%.cpp=$(BUILD)\%.o)

CC=g++
CFLAGS=-g -Wall -Werror
LFLAGS=-lm

all: clean $(EXE)

clean:
	if exist "$(EXE)" del $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)
