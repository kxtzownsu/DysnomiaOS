#include <iostream>
#include <string>

extern "C" {
    const char* input(const char* prompt) {
        static char buffer[256];  // Adjust the size as needed
        std::cout << prompt;

        // Set the width of the input to protect against buffer overflow
        std::cin.width(sizeof(buffer));

        // Read at most sizeof(buffer) - 1 characters to leave space for the null terminator
        std::cin.getline(buffer, sizeof(buffer));

        // Clear any remaining characters in the input buffer
        std::cin.clear();

        return buffer;
    }
}
