#include <stdio.h>
#include <stdlib.h>
#include "../../../libs/strings.h"
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void maininst(const char *installLocation){
  printf("Installing OS...\n");
  struct stat st;
  char cmd[1000];
  char mkdircmd[1000];
  char filePath[10000];
  // Check if the "rootfs" dir does not exist
  if (stat(installLocation, &st) == -1) {
      snprintf(mkdircmd, sizeof(mkdircmd), "mkdir %s", installLocation);
      printf("The directory %s does not exist.\n", installLocation);
      system(mkdircmd);
  };
  // Extract rootfs to install location
  snprintf(cmd, sizeof(cmd), "tar -xvf rootfs.tar.gz -C \"%s\"", installLocation);
  system(cmd);

  // Make Registry with Install Location, its going at "installLocation"
  sprintf(filePath, "%s/reg", installLocation);
  FILE *reg = fopen(filePath, "w");

  // Check if the file was successfully opened
  if (reg == NULL) {
      printf("Error opening file!\n");
      return 1; // Exit with an error code
  }

  // Write the registry values
  fprintf(reg, "REG=\"DysnomiaOS Registry v1\"\nROOTFS_DIR=\"%s/rootfs\"", installLocation);

  // Close the file
  fclose(reg);
};