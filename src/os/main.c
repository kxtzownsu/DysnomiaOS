#include <stdio.h>
#include "libs/strings.h"
#include "libs/lib.h"
#include "boot/loader.h"
#include "sys/init.h"


int main() {
  bootseq();
  initos();
  return 0;
}