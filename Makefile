CC=g++
CFLAGS=-Wall
DEBUG=-ggdb
CREATE_DIR_CMD=

ifeq ($(OS),Windows_NT)
	CREATE_DIR_CMD=if not exist \"$(OBJ_DIR)\" mkdir $(OBJ_DIR)
else
	CREATE_DIR_CMD=mkdir -p $(OBJ_DIR)
endif

SOURCES=main.cpp animal.cpp zooshop.cpp interface.cpp

OBJ_DIR=obj
OBJECTS=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

TARGET=zooshop

.PHONY: all clean $(OBJ_DIR)

all: $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJECTS) -o $@
	
$(OBJ_DIR)/main.o: main.cpp
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@
	
$(OBJ_DIR):
	@$(CREATE_DIR_CMD)

clean:
	rm -rf $(OBJ_DIR)/*
	rm -f $(TARGET)
