/** \file odsatransform.c
 *
 *  \brief This source contains the external and hidden global variables, function definition for odsa transform
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug Cannot support anything other than ASCII.
 */
#include <stdio.h>
#include <stdlib.h>
#include "odsautil.h"
#include "odsaoutputmap.h"
#include "odsatransform.h"

/*! \var long long int size
 *  \brief Variable to hold the input text size
 */
long long int size;

/*! \var input_data in_data
 *  \brief Variable to hold the input data
 */
input_data in_data;

/*! \var char last_letter
 *  \brief Vairable to hold the last letter
 */
char last_letter;

/*! \var long long int last_position
 *  \brief Variable to hold the last position
 */
long long int last_position;

/*! \var int jump_count
 *  \brief Variable to hold the number of jumps happened
 */
int jump_count;

/*! \var long long int current_size
 *  \brief Variable to hold the current data's length
 */
long long int current_size;

// odsa transform caried out at each iteration
char * iteration_transform(char * data, FILE *file) {

  if(in_data.input_text == NULL){
    printf("Input source has not been properly fetched.It appears null.\n");
    return;
  }
  if(data == NULL) {
    printf("Input data is null.\n");
  }
  last_position = 0LL;
  last_letter = data[0];
  in_data.letter_output_map = append_letter(data[0], in_data.letter_output_map);
  in_data.index_output_map = append_index(0LL, in_data.index_output_map);
  in_data.last_buffer_length = 1LL;
  jump_count = 0;
  in_data.just_appended = false;
  while(data[last_position+1LL] != '\0') {
    if(data[last_position+1LL] < last_letter) {
      in_data.letter_jump_map = append_letter(data[last_position+1LL], in_data.letter_jump_map);
      in_data.index_jump_map = append_index(last_position+1LL, in_data.index_jump_map);
      jump_count++;
      if(!contains_letter(data[last_position+1LL], in_data.letter_output_map)) {
        long long int index = 0LL;
        long long int loop_index = map_length_letter(in_data.letter_output_map);
        bool flag = false;
        char item;
        loop_index = 0LL;
        in_data.letter_output_map = go_up_letter(in_data.letter_output_map);
        in_data.index_output_map  = go_up_index(in_data.index_output_map);
        for(item = in_data.letter_output_map->data; loop_index <= map_length_last_call;) {
          if(item > data[last_position+1LL] && flag == false) {
            index = loop_index;
            flag = true;
            in_data.letter_output_map = append_letter_at(data[last_position+1LL], in_data.letter_output_map, index-1LL);
            in_data.index_output_map = append_index_at(in_data.index_output_map->data, in_data.index_output_map, index-1LL);
          } else if(flag == true) {
            in_data.index_output_map->data += 1LL;
          }
          if(in_data.letter_output_map->next != NULL) {
            in_data.letter_output_map = in_data.letter_output_map->next;
            in_data.index_output_map = in_data.index_output_map->next;
            item = in_data.letter_output_map->data;
          }
          loop_index++;
        }
      } else {

        long long int x = map_length_letter(in_data.letter_output_map);
        x = 0LL;
        in_data.index_output_map = go_up_index(in_data.index_output_map);
        while (x <= map_contains_letter_position) {
          in_data.index_output_map = in_data.index_output_map->next;
          x++;
        }
        while(x < map_length_last_call) {
          in_data.index_output_map->data += 1LL;
          if(in_data.index_output_map->next != NULL) {
            in_data.index_output_map = in_data.index_output_map->next;
          }
          x++;
        }
      }
    } else {
      if(!contains_letter(data[last_position+1LL], in_data.letter_output_map)) {
        in_data.letter_output_map = append_letter(data[last_position+1LL], in_data.letter_output_map);
        in_data.index_output_map = append_index(in_data.index_output_map->data + in_data.last_buffer_length, in_data.index_output_map);
        in_data.last_buffer_length = 1LL;
      } else {
        if(map_contains_letter_position == map_length_letter(in_data.letter_output_map)-1LL) {
          in_data.last_buffer_length++;
        } else {
          long long int x = map_length_last_call;
          x = 0LL;
          in_data.index_output_map = go_up_index(in_data.index_output_map);
          while (x <= map_contains_letter_position) {
            in_data.index_output_map = in_data.index_output_map->next;
            x++;
          }
          while(x < map_length_last_call) {
            in_data.index_output_map->data += 1LL;
            if(in_data.index_output_map->next != NULL) {
              in_data.index_output_map = in_data.index_output_map->next;
            }
            x++;
          }
        }
      }
    }
    in_data.letter_output_map = go_down_letter(in_data.letter_output_map);
    last_letter = in_data.letter_output_map->data;
    last_position++;
    if(jump_count >= MAX_JUMP_LENGTH) {
      print_map_letter_to_file(in_data.letter_output_map, file);
      print_map_index_to_file(in_data.index_output_map, file);
      fprintf(file, "%lld \n",in_data.index_output_map->data+in_data.last_buffer_length);
      if(in_data.letter_jump_map != NULL){
        print_map_letter_to_file_reverse(in_data.letter_jump_map, file);
      }
      if(in_data.index_jump_map != NULL) {
        print_map_index_to_file_reverse(in_data.index_jump_map, file);
      }

      fprintf(file, "\n");
      current_size -= last_position+1LL;
      if(current_size == 0LL) {
        return NULL;
      }
      return &data[last_position+1LL];
    }
  }
  print_map_letter_to_file(in_data.letter_output_map, file);
  print_map_index_to_file(in_data.index_output_map, file);
  fprintf(file, "%lld \n",in_data.index_output_map->data+in_data.last_buffer_length);
  if(in_data.letter_jump_map != NULL){
    print_map_letter_to_file_reverse(in_data.letter_jump_map, file);
  }
  if(in_data.index_jump_map != NULL) {
    print_map_index_to_file_reverse(in_data.index_jump_map, file);
  }
  return NULL;
}


output_map_letter * elloborate(output_map_letter * letter, output_map_index * index) {

  //Validating the parameters.
  if(letter == NULL) {
    printf("The parameter passed, letter for eloborating is null\n");
    return NULL;
  }
  if(index == NULL) {
    printf("The parameter passed, index for eloborating is null\n");
    return NULL;
  }

  //Variable to hold the loop's iteration length.
  long long int loop_length = map_length_letter(letter);
  long long int loop_variable = 0LL;
  output_map_letter * output = NULL;

  //Going up to the begining of the node.
  index = go_up_index(index);
  letter = go_up_letter(letter);
  while(loop_variable < loop_length) {
    long long int inner_loop_variable = index->data;
    while(inner_loop_variable < index->next->data) {
      output = append_letter(letter->data, output);
      inner_loop_variable++;
    }
    letter = letter->next;
    index = index->next;
    loop_variable++;
  }
  return output;
}


output_map_letter * reverse_jumps(
  output_map_letter * letter, output_map_index * index, output_map_letter * output) {

  //Validating the parameters.
  if(letter == NULL) {
    printf("The parameter passed, letter for reverse jumps is null\n");
    return NULL;
  }
  if(index == NULL) {
    printf("The parameter passed, index for reverse jumps is null\n");
    return NULL;
  }
  if(output == NULL) {
    printf("The parameter passed, output for reverse jumps is null\n");
    return NULL;
  }

  long long int loop_length = map_length_letter(letter);
  long long int loop_variable = 0LL;
  bool dummy_variable;
  letter = go_up_letter(letter);
  index = go_up_index(index);
  while (loop_variable < loop_length) {
    dummy_variable = contains_letter(letter->data, output);
    if(!dummy_variable) {
      printf("The searched letter %c is inavailable in the output map.\n", letter->data);
      return NULL;
    }
    output = re_position_letter_node(output, map_contains_letter_position, index->data);
    loop_variable++;
    letter = letter->next;
    index = index->next;
  }
  return output;
}

void delete_input_data() {
  delete_map_letter(in_data.letter_output_map);
  delete_map_index(in_data.index_output_map);
  delete_map_letter(in_data.letter_jump_map);
  delete_map_index(in_data.index_jump_map);
  free(in_data.input_text);
}

void delete_data(input_data data) {
  delete_map_letter(in_data.letter_output_map);
  delete_map_index(in_data.index_output_map);
  delete_map_letter(in_data.letter_jump_map);
  delete_map_index(in_data.index_jump_map);
  free(data.input_text);
}


void read_input_file(FILE *file){

  //Variable to hold the characters in the input file.
  char c;

  size = 0LL;
  fseek(file, 0, SEEK_SET);
  //Assement of input data size
  c = fgetc(file);
  while (c != EOF) {
    size++;
    c = fgetc(file);
  }

  //Reading the contents of the file
  in_data.input_text = (char *)calloc(size+1, sizeof(char));
  fseek(file, 0, SEEK_SET);
  fread(in_data.input_text, 1, size, file);
  fseek(file, 0, SEEK_SET);
  current_size = size;
}

long long int get_input_file_size() {
  return size;
}

void re_initialize_transform_variables() {
  delete_map_letter(in_data.letter_output_map);
  delete_map_index(in_data.index_output_map);
  if(in_data.letter_jump_map != NULL) {
    delete_map_letter(in_data.letter_jump_map);
  }
  if(in_data.index_jump_map != NULL) {
    delete_map_index(in_data.index_jump_map);
  }
  in_data.letter_output_map = NULL;
  in_data.index_output_map = NULL;
  in_data.letter_jump_map = NULL;
  in_data.index_jump_map = NULL;
  in_data.last_buffer_length = 0LL;
  in_data.just_appended = false;
  last_position = 0LL;
  jump_count = 0;
  last_letter = '\0';
  re_initialize_outputmap_variables();
}

void transform_data(const char *output_file) {
  //Variable for holding the out file.
  FILE *file;
  //Variable for holding the input text.
  char * data;
  //Opening the file for appending.
  file = fopen(output_file, "wb");
  if(file == NULL) {
    printf("Error in opening the file for writing.\n");
    return;
  }
  fprintf(file, "\n");
  fclose(file);
  file = fopen(output_file, "w");
  data = in_data.input_text;
  while(data != NULL && data[0] != 0) {
    data = iteration_transform(data, file);
    re_initialize_transform_variables();
  }
  free(in_data.input_text);
  fclose(file);
}

void reverse_transform_data(FILE *input_file, const char *output_file, const char *output_status) {
  //Variable for holding the out file.
  FILE *file;
  //Variable for holdingt the state of reading.. letter_output, letter_jump,
  //                                             index_output, index_jump.
  reading_status status = LETTER_OUTPUT;
  //Variable for holding the output.
  output_map_letter * output = NULL;
  //Variable for holding reading while reading.
  char c;
  //Variable for reading long long int from input.
  long long int indices = 0LL;
  //Variables for holding the input size and output size.
  long long int in_size = 0LL, theoretical_out_size = 0LL, original_out_size = 0LL;

  //Opening the file for appending.
  file = fopen(output_file, "wb");
  if(file == NULL) {
    printf("Error in opening the file for writing.\n");
    return;
  }

  in_data.letter_output_map = NULL;
  in_data.index_output_map = NULL;
  in_data.letter_jump_map = NULL;
  in_data.index_jump_map = NULL;
  fseek(input_file, 0, SEEK_SET);
  //Reading the data.
  c = fgetc(input_file);
  fseek(input_file, -1L, SEEK_CUR);
  while (c > 0) {
    if((status == INDEX_OUTPUT || status == INDEX_JUMP)) {
      indices = 0LL;
      c = fgetc(input_file);
      while(c != 32 && c != 10) {
        indices = indices*10LL + (long long int)(c - 48);
        c = fgetc(input_file);
      }
    } else {
      c = fgetc(input_file);
    }
    if(c != 10 && c > 0 && (status == INDEX_OUTPUT || status == INDEX_JUMP)) {
      if(status == INDEX_OUTPUT) {
        in_data.index_output_map = append_index(indices, in_data.index_output_map);
      } else if(status == INDEX_JUMP){
        in_data.index_jump_map = append_index(indices, in_data.index_jump_map);
      }
    } else if(c > 0 && (status == LETTER_OUTPUT || status == LETTER_JUMP)) {
      if(status == LETTER_OUTPUT) {
        in_data.letter_output_map = append_letter(c, in_data.letter_output_map);
      } else if(status == LETTER_JUMP) {
        in_data.letter_jump_map = append_letter(c, in_data.letter_jump_map);
      }
    } else if(c == -2){
      if(status == LETTER_OUTPUT) {
        status = INDEX_OUTPUT;
      } else if(status == LETTER_JUMP) {
        status = INDEX_JUMP;
      }
    } else if(c == 10){
      if(status == INDEX_OUTPUT) {
        status = LETTER_JUMP;
      } else if(status == INDEX_JUMP) {
        status = LETTER_OUTPUT;
        output = elloborate(in_data.letter_output_map, in_data.index_output_map);
        if(in_data.letter_jump_map != NULL) {
          output = reverse_jumps(in_data.letter_jump_map, in_data.index_jump_map, output);
        }
        print_map_letter_to_file_as_plaintext(output, file);
        in_size += map_length_letter(output);
        theoretical_out_size += map_length_letter(in_data.letter_output_map);
        theoretical_out_size += map_length_letter(in_data.letter_jump_map);
        theoretical_out_size += map_length_index(in_data.index_output_map);
        theoretical_out_size += map_length_index(in_data.index_jump_map);
        original_out_size += map_length_letter(in_data.letter_output_map)+1LL;
        original_out_size += map_length_letter(in_data.letter_jump_map)*2+3LL;
        original_out_size += map_length_index(in_data.index_output_map)+1LL;
        original_out_size += map_length_index(in_data.index_jump_map)*2+1LL;
        re_initialize_transform_variables();
        delete_map_letter(output);
        output = NULL;
      }
    }
    if (c == -2) {
      c = 10;
    }
  }
  fclose(file);
  file = fopen(output_status, "wb");
  if(file == NULL) {
    printf("Error in opening the file for updating the status.\n");
    return;
  }
  original_out_size += 1LL;
  fprintf(file, "Decompression was successful.\n");
  fprintf(file, "Input Size              : %lld bytes\n", in_size);
  fprintf(file, "Theoretical Output Size : %lld bytes\n", theoretical_out_size);
  fprintf(file, "Original Output Size    : %lld bytes\n", original_out_size);
  fprintf(file, "Theoretical Efficiency  : %lld %%\n", (100LL - (theoretical_out_size*100LL/in_size)));
  fprintf(file, "Original Efficiency     : %lld %%\n", (100LL - (original_out_size*100LL/in_size)));
  fclose(file);
}
