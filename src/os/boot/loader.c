#include "../libs/strings.h"
#include "../libs/lib.h"
#include "loader.h"
#include <stdio.h>
#include <stdlib.h>

void bootseq(){
  int total_items = 100;
  int bar_length = 16;

  int res = system("clear");
  if (res == 69) {
    printf("Could not clear screen\n");
    exit(1);
  }
  printf("Booting %s %s\n", osName, osVersion);
  progress_bar(total_items, bar_length);
}