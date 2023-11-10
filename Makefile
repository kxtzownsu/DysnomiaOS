# Define the source directory
SRC_DIR = src

# Define the build directory
BUILD_DIR = build

# Collect all source files recursively
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')

# Compiler and flags
CC = gcc
CFLAGS += -g -Wno-everything -pthread -lm

# Targets
all: main

main:
	$(CC) -o $(BUILD_DIR)/os $(SRC_FILES)
	rm -rf $(BUILD_DIR)/obj/*.o

full: main clean run

run:
	clear
	./$(BUILD_DIR)/os

clean:
	rm -f main main-debug
	rm -rf a.out
	rm -rf $(BUILD_DIR)/obj/*

# Rule to build object files from source files
$(BUILD_DIR)/obj/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
