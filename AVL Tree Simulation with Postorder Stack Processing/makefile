CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
TARGET = AvlAgaci_Yigin
SOURCE_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SOURCES))

ifdef SystemRoot  # Windows için kontrol
	EXE_EXT = .exe
else
	EXE_EXT =
endif

$(BIN_DIR)/$(TARGET)$(EXE_EXT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(LIB_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run:
	clear && make
	cd $(BIN_DIR) && ./$(TARGET)$(EXE_EXT)

clean:
	rm -f $(LIB_DIR)/*.o $(BIN_DIR)/$(TARGET)$(EXE_EXT)
