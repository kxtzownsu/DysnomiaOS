# Define the source directory
OS_DIR = src/os
INST_DIR = src/installer

# Define the build directory
BUILD_DIR = build

# Collect all source files recursively
INST_FILES := $(shell find $(INST_DIR) -name '*.c')
OS_FILES := $(shell find $(OS_DIR) -name '*.c')

# Compiler and flags
CC = gcc
CFLAGS += -g -Wno-everything -pthread -lm -static

# Targets
all: main

main: full

installer:
	$(CC) -o $(BUILD_DIR)/inst/boot $(INST_FILES)
	rm -rf $(BUILD_DIR)/obj/*.o

os:
	$(CC) -o $(BUILD_DIR)/os/boot $(OS_FILES)
	rm -rf $(BUILD_DIR)/obj/*.o

full: installer os clean runinst runos

runos:
	clear
	bash runos.sh

runinst:
	clear
	bash runinst.sh

clean:
	rm -f main main-debug
	rm -rf a.out
	rm -rf $(BUILD_DIR)/obj/*

# Rule to build object files from source files
$(BUILD_DIR)/obj/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
