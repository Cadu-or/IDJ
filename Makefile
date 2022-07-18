TARGET_EXEC := game
FLAGS := -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

CMP_DIR := ./src/components

CMPS := $(shell find $(CMP_DIR) -name '*.cpp')

all:
	g++ -std=c++11 $(CMPS) -o $(TARGET_EXEC) $(FLAGS)
	./$(TARGET_EXEC)