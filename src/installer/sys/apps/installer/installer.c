#include <stdio.h>
#include <stdlib.h>
#include "../../../libs/strings.h"

void maininst(const char *installLocation){
  printf("Installing OS...\n");
  // Open the file
  char cmd[1000];
  strcpy(cmd, "cd ");
  strcat(cmd, installLocation);
  system(cmd);
  FILE *currentfile = fopen("installer.txt", "w");

  // Error Handler
  if (currentfile == NULL) {
    printf("Error with installer. Exiting... \n");
    exit(1);
  }

  fprintf(currentfile, "This was made using installer version %s", osVersion);

  fclose(currentfile);
};




// This was a test
void makehelloworld(){
  // Open the file in write mode ("w")
  FILE *file = fopen("helloworld.txt", "w");

  // Check if the file was successfully opened
  if (file == NULL) {
      printf("Error opening file!\n");
      return 1; // Exit with an error code
  }

  // Write "Hello, World!" to the file
  fprintf(file, "Hello, World!");

  // Close the file
  fclose(file);
};