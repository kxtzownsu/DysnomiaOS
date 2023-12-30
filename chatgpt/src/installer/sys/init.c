#include <stdio.h>
#include <stdlib.h>
#include "../libs/strings.h"
#include "../libs/lib.h"
#include "apps/installer/installer.h"


void initos(const char *installLocation){
  system("clear");
  printf("Dysnomia Kernel %s\n", osVersion);
  maininst(installLocation);
}