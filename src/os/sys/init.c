#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include "../libs/strings.h"
#include "../libs/lib.h"
#include "../libs/kernmsg.h"

void startModules(struct MessageBuffer *buffer) {
    printf("Starting modules...\n");
    kernmsg(buffer, "norm", "init", "Starting modules");

    // Open the modules directory
    DIR *dir = opendir("modules");
    if (dir == NULL) {
        printf("[ERROR] Unable to open modules directory\n");
        kernmsg(buffer, "err", "init", "Unable to open modules directory");
        return;
    }

    // Read entries in the modules directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Form the full path of the module executable
        char modulePath[256];
        snprintf(modulePath, sizeof(modulePath), "modules/%s", entry->d_name);

        // Execute the module
        int result = system(modulePath);

        // Check the result of the module execution
        if (result != 0) {
            printf("[ERROR] Module %s failed to start\n", entry->d_name);
            kernmsg(buffer, "err", "init", "Module failed to start");
        } else {
            printf("Module %s started successfully\n", entry->d_name);
            kernmsg(buffer, "norm", "init", "Module started successfully");
        }
    }

    // Close the modules directory
    closedir(dir);

    printf("Modules initialization complete.\n");
    kernmsg(buffer, "norm", "init", "Modules initialization complete");
}


void checkforroot(struct MessageBuffer *buffer){
  printf("Checking for rootfs\n");
  kernmsg(buffer, "norm", "init", "checking for rootfs");
  struct stat st;

  if (stat("rootfs", &st) == -1) {
      printf("[ERROR] Rootfs not found\n");
      kernmsg(buffer, "err", "init", "rootfs not found");
      exit(1);
  }

  // Check if it's a directory
  if (S_ISDIR(st.st_mode)) {
      printf("Rootfs found.\n");
  } else {
      printf("[ERROR] Rootfs is not a directory\n");
      kernmsg(buffer, "err", "init", "rootfs is not a directory");
      exit(1);
  }
  printf("Check completed. Rootfs found.\n");
  kernmsg(buffer, "norm", "init", "rootfs found");
}

void initos(struct MessageBuffer *buffer){
  int res = system("clear");
  if (res == 69) {
    printf("Could not clear screen\n");
    exit(1);
  }
  printf("Dysnomia Kernel %s\n", osVersion);
  kernmsg(buffer, "norm", "init", "Dysnomia Kernel 0.1");
  checkforroot(buffer);
  displayMessages(buffer);
  startModules(buffer);
  termInitialize(buffer);
}