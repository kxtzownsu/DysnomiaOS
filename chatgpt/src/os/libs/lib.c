#include <stdio.h>
#include "lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "kernmsg.h"

void print(const char *str) {
    printf("%s\n", str);
}

void progress_bar(int total, int length) {
    int i;
    for (i = 0; i <= total; i++) {
        float percent = ((float)i / total) * 100;
        int filled_length = (int)((length * i) / total);

        printf("\r[");
        for (int j = 0; j < filled_length; j++) {
            printf("#");
        }
        for (int j = filled_length; j < length; j++) {
            printf("-");
        }

        printf("] %.2f%%", percent);
        fflush(stdout);

        // Simulate some task (replace with actual task)
        usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds)
    }
    printf("\n");
}

const char* input(const char* prompt) {
    printf("%s", prompt);

    // Allocate memory dynamically for the buffer
    char* buffer = NULL;
    size_t buffer_size = 0;

    // Read input
    if (getline(&buffer, &buffer_size, stdin) != -1) {
        // Remove the newline character at the end
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Duplicate the string using malloc
        char* result = (char*)malloc(len + 1);
        if (result != NULL) {
            strcpy(result, buffer);
        }

        // Free the original buffer
        free(buffer);

        return result;
    }

    // In case of error or end of file
    return NULL;
}


