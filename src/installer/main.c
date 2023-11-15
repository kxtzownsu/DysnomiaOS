#include <stdio.h>
#include <stdlib.h>
#include "libs/strings.h"
#include "libs/lib.h"
#include "boot/loader.h"
#include "sys/init.h"
#include "sys/apps/installer/installer.h"


int main() {
  bootseq();
  initos();
  return 0;
}


