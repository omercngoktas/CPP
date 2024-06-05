
CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

TARGET = stack_bst_ascii
SOURCE_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)

OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SOURCES))

$(BIN_DIR)/$(TARGET).exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(LIB_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_DIR)/*.o $(BIN_DIR)/$(TARGET).exe
