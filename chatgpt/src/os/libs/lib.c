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