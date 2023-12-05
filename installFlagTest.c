#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if there are at least two arguments (program name and at least one command-line argument)
    if (argc < 2) {
        printf("Usage: %s --inst <installLocation>\n", argv[0]);
        return 1;
    }

    // Loop through command-line arguments
    for (int i = 1; i < argc; ++i) {
        // Check if the current argument is the --inst flag
        if (strcmp(argv[i], "--inst") == 0) {
            // Check if there is an argument after the --inst flag
            if (i + 1 < argc) {
                // Get the install location from the next argument
                char *installLocation = argv[i + 1];
                printf("Install location: %s\n", installLocation);
                // Add your installation logic here

                return 0; // You can exit the program or continue with the rest of your logic
            } else {
                printf("Error: Missing install location after --inst flag\n");
                return 1;
            }
        }
    }

    printf("Error: --inst flag not found\n");
    return 1;
}
