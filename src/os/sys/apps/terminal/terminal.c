#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../../../libs/lib.h"
#include "../../../libs/kernmsg.h"
#include "../calculator/calc.h"

// extern const char* prompt);

void handleCommand(const char* command, struct MessageBuffer *buffer) {
    char lowercaseCommand[256];
    strncpy(lowercaseCommand, command, sizeof(lowercaseCommand));

    // Converust the command to lowercase for case-insensitive matching
    for (int i = 0; lowercaseCommand[i]; i++) {
        lowercaseCommand[i] = tolower(lowercaseCommand[i]);
    }

    if (strcmp(lowercaseCommand, "help") == 0) {
        printf("Available commands:\n");
        printf("  help       - Display this help message\n");
        printf("  clear      - Clear the terminal screen\n");
        printf("  exit       - Exit the fish terminal\n");
        printf("  calculator - Launch the calculator\n");
        printf("  settings   - Open the settings editor\n");
        printf("  clock      - Display the current time\n");
        printf("  calendar   - Display a calendar\n");
        printf("  weather    - Check the weather\n");
        printf("  files      - List files in the current directory\n");
        printf("  music      - Play some music\n");
        printf("  chat       - Start a terminal chat application\n");
        printf("  kmsgs      - View kernel logs\n");
        printf("  shell      - Open a `bash` shell\n");
    } else if (strcmp(lowercaseCommand, "clear") == 0) {
        // Assuming a UNIX-like system; you might need to adjust this for Windows
        printf("\033[H\033[J");  // ANSI escape codes to clear the terminal
    } else if (strcmp(lowercaseCommand, "calculator") == 0) {
        calc();
        printf("\n");
    } else if (strcmp(lowercaseCommand, "settings") == 0) {
        printf("Opening the settings editor...\n");
        // Implement the settings editor logic or execute a settings program
    } else if (strcmp(lowercaseCommand, "clock") == 0) {
        // Implement the clock functionality
    } else if (strcmp(lowercaseCommand, "calendar") == 0) {
        // Implement the calendar functionality
    } else if (strcmp(lowercaseCommand, "weather") == 0) {
        // Implement the weather functionality
    } else if (strcmp(lowercaseCommand, "files") == 0) {
        // Implement the file listing functionality
    } else if (strcmp(lowercaseCommand, "music") == 0) {
        // Implement the music player functionality
    } else if (strcmp(lowercaseCommand, "chat") == 0) {
        // Implement the terminal chat application
    } else if (strcmp(lowercaseCommand, "shell") == 0) {
      system("bash");
    } else if (strcmp(lowercaseCommand, "kmsgs") == 0) {
      displayMessages(buffer);
    } else if (strcmp(lowercaseCommand, "") ==0) {
        // ignore enter
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void termInitialize(struct MessageBuffer *buffer) {
    struct stat st;

    if (stat("data.json", &st) == -1) {
        getStarted();
    }
    printf("Welcome to the DysnomiaOS terminal!\n");
    printf("Run `help` to see all commands\n");
    while (1) {
        const char* userInput = input("kxtzownsu@kxtz-laptop ~> ");
        if (strcmp(userInput, "exit") == 0) {
          free((void*)userInput);
          exit(0);
        }
        handleCommand(userInput, buffer);
    }
}