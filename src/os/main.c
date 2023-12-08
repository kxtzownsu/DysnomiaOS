#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/strings.h"
#include "libs/lib.h"
#include "libs/kernmsg.h"
#include "sys/init.h"
#include "boot/loader.h"

int main(int argc, char *argv[]) {
  struct MessageBuffer buffer;
  initMessageBuffer(&buffer);
  int skipBootAnimation = 0;

  // Check command line arguments
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--skip-boot-animation") == 0 || strcmp(argv[i], "-s") == 0) {
      skipBootAnimation = 1;
    }
  }

  if (skipBootAnimation) {
    initos(&buffer);
  } else {
    bootseq();
    initos(&buffer);
  }
  return 0;
}
