/** \file Transform.c
 *
 *  \brief This program contains the test suite for forward odsa tranform
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
  if( argc < 3) {
    printf("Proper usage is ./Transform [source-filename] [destination-filename]\n");
    return 0;
  }

  //Checking if a file with given name exists.
  input_file = fopen(argv[1], "rb");
  if(input_file == NULL) {
    printf("Error in opening the input file\n");
    return 0;
  }

  //Reading the data from input file and putting in in_data
  read_input_file(input_file);
  transform_data(argv[2]);
  fclose(input_file);
  return 0;
}
