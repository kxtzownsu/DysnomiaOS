#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 256

struct MessageBuffer {
    char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
    int messageCount;
};

void initMessageBuffer(struct MessageBuffer *buffer) {
    buffer->messageCount = 0;
}

void addMessage(struct MessageBuffer *buffer, const char *type, const char *title, const char *message) {
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    if (buffer->messageCount < MAX_MESSAGES) {
        // Format the date
        strftime(buffer->messages[buffer->messageCount], MAX_MESSAGE_LENGTH, "\033[0;32m%H:%M:%S %Y-%m-%d\033[0m", tm_info);

        // Append the title with color coding
        if (strcmp(type, "err") == 0) {
            snprintf(buffer->messages[buffer->messageCount] + strlen(buffer->messages[buffer->messageCount]), 
                     MAX_MESSAGE_LENGTH - strlen(buffer->messages[buffer->messageCount]),
                     " \033[0;31m%s\033[0m", title);
        } else if (strcmp(type, "warn") == 0) {
            snprintf(buffer->messages[buffer->messageCount] + strlen(buffer->messages[buffer->messageCount]), 
                     MAX_MESSAGE_LENGTH - strlen(buffer->messages[buffer->messageCount]),
                     " \033[0;33m%s\033[0m", title);
        } else {
            snprintf(buffer->messages[buffer->messageCount] + strlen(buffer->messages[buffer->messageCount]), 
                     MAX_MESSAGE_LENGTH - strlen(buffer->messages[buffer->messageCount]),
                     " \033[0;36m%s\033[0m", title);
        }

        // Append the space between title and message
        snprintf(buffer->messages[buffer->messageCount] + strlen(buffer->messages[buffer->messageCount]), 
                 MAX_MESSAGE_LENGTH - strlen(buffer->messages[buffer->messageCount]),
                 " ");

        // Append the message
        snprintf(buffer->messages[buffer->messageCount] + strlen(buffer->messages[buffer->messageCount]), 
                 MAX_MESSAGE_LENGTH - strlen(buffer->messages[buffer->messageCount]),
                 "%s", message);

        buffer->messageCount++;
    } else {
        printf("Message buffer is full\n");
    }
}


void freeMessageBuffer(struct MessageBuffer *buffer) {
    // If there are no dynamically allocated resources in MessageBuffer, you can simply free the buffer itself
    free(buffer);
}


void displayMessages(struct MessageBuffer *buffer) {
    for (int i = 0; i < buffer->messageCount; ++i) {
        printf("%s\n", buffer->messages[i]);
    }
}

void kernmsg(struct MessageBuffer *buffer, const char *type, const char *title, const char *message) {
    // Check message type and add to the buffer
    addMessage(buffer, type, title, message);
}