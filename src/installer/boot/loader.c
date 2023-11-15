#include "../libs/strings.h"
#include "../libs/lib.h"
#include "loader.h"
#include <stdio.h>

void bootseq(){
  int total_items = 100;
  int bar_length = 16;

  system("clear");
  printf("Booting %s %s\n", osName, osVersion);
  progress_bar(total_items, bar_length);
}