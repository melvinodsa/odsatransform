/** \file ReverseTransform.c
 *
 *  \brief This program contains the test suite for reverse odsa tranform
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug No known bugs.
 */
#include <stdio.h>
#include "../Code/odsautil.h"
#include "../Code/odsaoutputmap.h"
#include "../Code/odsatransform.h"

int main(int argc, char const *argv[]) {

  //Variable for holding the input file.
  FILE *input_file;

  //Checking the number of arguments passed.
  if( argc < 4) {
    printf("Proper usage is ./ReverseTransform [source-filename] [destination-filename] [status-filename]\n");
    return 0;
  }

  //Checking if a file with given name exists.
  input_file = fopen(argv[1], "rb");
  if(input_file == NULL) {
    printf("Error in opening the input file\n");
    return 0;
  }
  reverse_transform_data(input_file, argv[2], argv[3]);
  fclose(input_file);
  return 0;
}
