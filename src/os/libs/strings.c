#include "strings.h"
#include <string.h>

char osFull[50];
char kernFull[50];

// OS info
const char osName[] = "DysnomiaOS";
const char osVersion[] = "0.1";

// Kernel info
const char kernelName[] = "Dysnomia Kernel";
const char kernelVersion[] = "0.1";

void initializeStrings() {
    strcpy(osFull, osName);
    strcat(osFull, " ");
    strcat(osFull, osVersion);

    strcpy(kernFull, kernelName);
    strcat(kernFull, " ");
    strcat(kernFull, kernelVersion);
}
