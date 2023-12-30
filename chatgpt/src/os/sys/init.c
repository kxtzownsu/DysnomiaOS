#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../libs/strings.h"
#include "../libs/lib.h"
#include "../libs/kernmsg.h"


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
}