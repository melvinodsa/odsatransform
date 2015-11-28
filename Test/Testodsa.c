/** \file Testodsa.c
 *
 *  \brief This program contains the test suite for odsa librraies
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug No known bugs.
 */
#include <stdlib.h>
#include <stdio.h>
#include "../Code/odsautil.h"
#include "../Code/odsaoutputmap.h"
#include "../Code/odsatransform.h"

int main(int argc, char const *argv[]) {
  FILE * file;
  file = fopen(argv[1], "r");

  char c = fgetc(file);
  while(c != '\0' && c != -1) {
    printf("%d %c\n", c, c );
    c = fgetc(file);
  }
  return 0;
}
