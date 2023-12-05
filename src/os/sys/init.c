#include <stdio.h>
#include <stdlib.h>
#include "../libs/strings.h"
#include "../libs/lib.h"

void checkforroot(){
  printf("Checking for rootfs\n");
  
}

void initos(){
  system("clear");
  printf("Dysnomia Kernel %s\n", osVersion);
  checkforroot();
}