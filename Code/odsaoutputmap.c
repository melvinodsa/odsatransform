/** \file odsaoutputmap.c
 *
 *  \brief This source contains the external global variables, function definition for odsa output maps
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug Cannot support anything other than ASCII.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "odsautil.h"
#include "odsaoutputmap.h"

/*! \var long long int map_contains_letter_position
 *  \brief Variable holding the index of the character's position of last search in map
 */
long long int map_contains_letter_position;

/*! \var long long int map_length_last_call
 *  \brief Varirable holding the length of map on which last length function function was
 * applied
 */
 long long int map_length_last_call;

//Function to append a new node to the given one.
output_map_letter * append_letter(char data, output_map_letter * node) {
  if(node == NULL){
    node = (output_map_letter *)malloc(sizeof(output_map_letter));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
  }
  //Variable to hold the new node.
  output_map_letter *temp = malloc(sizeof(output_map_letter));
  //Initializing the new node.
  temp->next = NULL;
  temp->previous = node;
  temp->data = data;
  //Appending the new node to the given.
  node->next = temp;
  return temp;
}

//Function to append a new node to the given one.
output_map_index * append_index(long long int data, output_map_index * node) {
  if(node == NULL){
    node = (output_map_index *)malloc(sizeof(output_map_index));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
  }
  //Variable to hold the new node.
  output_map_index *temp = malloc(sizeof(output_map_index));
  //Initializing the new node.
  temp->next = NULL;
  temp->previous = node;
  temp->data = data;
  //Appending the new node to the given.
  node->next = temp;
  return temp;
}


//Function to append a new node to the given one at a specific position.
output_map_letter * append_letter_at(char data, output_map_letter * node, long long int position) {
  if(node == NULL){
    node = (output_map_letter *)malloc(sizeof(output_map_letter));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
  }
  //Variable to hold the new node.
  output_map_letter *temp = malloc(sizeof(output_map_letter));
  //Iterating to the specific location.
  node = go_up_letter(node);
  if(position >= map_length_letter(node)) {
    printf("The given position is greater than the length of the map.\n");
    return node;
  }
  long long int tempPos = 0LL;
  if(position >= 0LL) {
    while(tempPos < position && position > 0LL) {
      node = node->next;
      tempPos++;
    }
    temp->previous = node;
    temp->data = data;
    temp->next = node->next;
    //Appending the new node to the given.
    node->next = temp;
    return node->next;
  } else {
    temp->previous = NULL;
    temp->data = data;
    temp->next = node;
    node->previous = temp;
    return node->previous;
  }
}

//Function to append a new node to the given one at a specific position.
output_map_index * append_index_at(long long int data, output_map_index * node, long long int position) {
  if(node == NULL){
    node = (output_map_index *)malloc(sizeof(output_map_index));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
  }
  //Variable to hold the new node.
  output_map_index *temp = malloc(sizeof(output_map_index));
  //Iterating to the specific location.
  node = go_up_index(node);
  if(position >= map_length_index(node)) {
    printf("The given position is greater than the length of the map.\n");
    return node;
  }
  long long int tempPos = 0LL;
  if(position >= 0LL) {
    while(tempPos < position && position > 0LL) {
      node = node->next;
      tempPos++;
    }
    temp->previous = node;
    temp->data = data;
    temp->next = node->next;
    //Appending the new node to the given.
    node->next = temp;
    return node->next;
  } else {
    temp->previous = NULL;
    temp->data = data;
    temp->next = node;
    node->previous = temp;
    return node->previous;
  }
}

//Function to delete the entire map.
void delete_map_letter(output_map_letter * node){

  if(node == NULL) {
    printf("Cannot delete the node cause it's null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_letter(node);
  //Iterating and deleting every node and freeing the memory.
  output_map_letter * tmp = NULL;
  while(node->next != NULL){
    tmp = node->next;
    free(node);
    node = tmp;
  }
  //Deleting the last node;
  free(node);
}

//Function to delete the entire map.
void delete_map_index(output_map_index * node){

  if(node == NULL) {
    printf("Cannot delete the node cause it's null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_index(node);
  //Iterating and deleting every node and freeing the memory.
  output_map_index * tmp = NULL;
  while(node->next != NULL){
    tmp = node->next;
    free(node);
    node = tmp;
  }
  //Deleting the last node;
  free(node);
}

//Function to go up the map. This has to be called each time we do any other function.
output_map_letter * go_up_letter(output_map_letter * node){
  if(node == NULL) {
    printf("Cannot go up the map cause the node is null.\n");
    return node;
  }
  //Iterating and going up to the top node.
  while (node->previous != NULL) {
    node = node->previous;
  }
  return node;
}

//Function to go up the map. This has to be called each time we do any other function.
output_map_index * go_up_index(output_map_index * node){
  if(node == NULL) {
    printf("Cannot go up the map cause the node is null.\n");
    return node;
  }
  //Iterating and going up to the top node.
  while (node->previous != NULL) {
    node = node->previous;
  }
  return node;
}

//Function to print the contents of the map.
void print_map_letter(output_map_letter * node){
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_letter(node);
  //Iterating and printing the contents of the map.
  while(node->next != NULL){
    printf("node addr: %p; previous : %p; data : %c; next : %p\n", node, node->previous, node->data, node->next);
    node = node->next;
  }
  printf("node addr: %p; previous : %p; data : %c; next : %p\n", node, node->previous, node->data, node->next);

}

//Function to print the contents of the output_map_letter to a file.
void print_map_letter_to_file(output_map_letter * node, FILE *file) {
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_letter(node);
  while(node->next != NULL){
    fprintf(file, "%c", node->data);
    node = node->next;
  }
  fprintf(file, "%c%c", node->data, -2);
}

//Function to print the contents of the output_map_letter to a file.
void print_map_letter_to_file_as_plaintext(output_map_letter * node, FILE *file) {
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_letter(node);
  while(node->next != NULL){
    fprintf(file, "%c", node->data);
    node = node->next;
  }
  fprintf(file, "%c", node->data);
}

//Function to print the contents of the output_map_letter to a file in reverse.
void print_map_letter_to_file_reverse(output_map_letter * node, FILE *file) {
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_down_letter(node);
  while(node->previous != NULL){
    fprintf(file, "%c", node->data);
    node = node->previous;
  }
  fprintf(file, "%c%c", node->data, -2);
}

//Function to print the contents of the map.
void print_map_index(output_map_index * node){
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_index(node);
  //Iterating and printing the contents of the map.
  while(node->next != NULL){
    printf("node addr: %p; previous : %p; data : %lld; next : %p\n", node, node->previous, node->data, node->next);
    node = node->next;
  }
  printf("node addr: %p; previous : %p; data : %lld; next : %p\n", node, node->previous, node->data, node->next);
}

//Function to print the contents of the output_map_letter to a file.
void print_map_index_to_file(output_map_index * node, FILE *file) {
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_up_index(node);
  while(node->next != NULL){
    fprintf(file, "%lld ", node->data);
    node = node->next;
  }
  fprintf(file, "%lld ", node->data);
}

//Function to print the contents of the output_map_letter to a file.
void print_map_index_to_file_reverse(output_map_index * node, FILE *file) {
  if(node == NULL) {
    printf("Cannot print the map cause the node is null.\n");
    return;
  }
  //Start from the begining of the map.
  node = go_down_index(node);
  while(node->previous != NULL){
    fprintf(file, "%lld ", node->data);
    node = node->previous;
  }
  fprintf(file, "%lld ", node->data);
}

//Function to print the contents of the map.
output_map_letter * go_down_letter(output_map_letter * node){
  if(node == NULL) {
    printf("Cannot go down the map cause the node is null.\n");
    return;
  }
  //Iterating and printing the contents of the map.
  while(node->next != NULL){
    node = node->next;
  }
  return node;
}

//Function to print the contents of the map.
output_map_index * go_down_index(output_map_index * node){
  if(node == NULL) {
    printf("Cannot go down the map cause the node is null.\n");
    return;
  }
  //Iterating and printing the contents of the map.
  while(node->next != NULL){
    node = node->next;
  }
  return node;
}

//Function to check whether a particular character is present in a map.
bool contains_letter(char data, output_map_letter * node) {
  if(node == NULL) {
    printf("Cannot check in the map cause the node is null.\n");
    return false;
  }
  //Start from the begining of the map.
  node = go_up_letter(node);
  //Iterating and searching for the data in the map.
  output_map_letter tmp = *node;
  map_contains_letter_position = 0LL;
  while(tmp.next != NULL){
    if(tmp.data == data){
      return true;
    }
    tmp = *tmp.next;
    map_contains_letter_position++;
  }
  if(tmp.data == data){
    return true;
  }
  return false;
}


//Function to return the length of the map.
long long int map_length_letter(output_map_letter * node){
  if(node == NULL) {
    printf("Cannot get the length of the map cause the node is null.\n");
    return 0LL;
  }
  long long int counter = 0LL;
  node = go_up_letter(node);
  while (node->next != NULL) {
    node = node->next;
    counter++;
  }
  map_length_last_call = ++counter;
  return counter;
}

//Function to return the length of the map.
long long int map_length_index(output_map_index * node){
  if(node == NULL) {
    printf("Cannot get the length of the map cause the node is null.\n");
    return 0LL;
  }
  long long int counter = 0LL;
  node = go_up_index(node);
  while (node->next != NULL) {
    node = node->next;
    counter++;
  }
  ++counter;
  return counter;
}

//Function to make a copy of gven map.
output_map_letter * copy_map_letter(output_map_letter * node, bool verification, int no_of_arguments, ...) {
  if(node == NULL) {
    printf("Cannot copy the map cause the node is null.\n");
    return NULL;
  }
  node = go_up_letter(node);
  va_list arguments;
  long long int start_index = 0LL;
  long long int length = map_length_letter(node);
  long long int end_index = length-1LL;
  long long int counter  = 0LL;

  va_start(arguments, no_of_arguments);
  //Checking the no of arguments and setting variables according.
  if(no_of_arguments > 0 && verification == false) {
    switch (no_of_arguments) {
      case 1:
        start_index = va_arg(arguments, long long int);
        end_index = length-1LL;
        break;
      case 2:
        start_index = va_arg(arguments, long long int);
        end_index = va_arg(arguments, long long int);
        if(end_index > length-1LL) end_index = length-1LL;
        break;
    }
    //Checking whether the starting index is greater than node length.
    if(start_index >= length){
      return NULL;
    }

    //Variable holding the value of the index to from which the slice has to be made.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
  } else if(verification == true){//verification will grand more performance.
    start_index = va_arg(arguments, long long int);
    end_index = va_arg(arguments, long long int);
    //Variable holding the value of the index to from which the slice has to be made.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
  }
  va_end(arguments);
  //Initializing the new node.
  output_map_letter *temp = malloc(sizeof(output_map_letter));
  temp->previous = NULL;
  temp->next = NULL;
  //Copying the nodes.
  while(counter < end_index){
    counter++;
    temp->data = node->data;
    temp->next = malloc(sizeof(output_map_letter));
    temp->next->previous = temp;
    temp = temp->next;
    node = node->next;
  }
  //Copying the last node.
  temp->next = NULL;
  temp->data = node->data;
  temp = go_up_letter(temp);
  return temp;
}

//Function to make a copy of gven map.
output_map_index * copy_map_index(output_map_index * node, bool verification, int no_of_arguments, ...) {
  if(node == NULL) {
    printf("Cannot copy the map cause the node is null.\n");
    return NULL;
  }
  node = go_up_index(node);
  va_list arguments;
  long long int start_index = 0LL;
  long long int length = map_length_index(node);
  long long int end_index = length-1LL;
  long long int counter  = 0LL;

  va_start(arguments, no_of_arguments);
  //Checking the no of arguments and setting variables according.
  if(no_of_arguments > 0 && verification == false) {
    switch (no_of_arguments) {
      case 1:
        start_index = va_arg(arguments, long long int);
        end_index = length-1LL;
        break;
      case 2:
        start_index = va_arg(arguments, long long int);
        end_index = va_arg(arguments, long long int);
        if(end_index > length-1LL) end_index = length-1LL;
        break;
    }
    //Checking whether the starting index is greater than node length.
    if(start_index >= length){
      return NULL;
    }

    //Variable holding the value of the index to from which the slice has to be made.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
  } else if(verification == true){//verification will grand more performance.
    start_index = va_arg(arguments, long long int);
    end_index = va_arg(arguments, long long int);
    //Variable holding the value of the index to from which the slice has to be made.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
  }
  va_end(arguments);
  //Initializing the new node.
  output_map_index *temp = malloc(sizeof(output_map_index));
  temp->previous = NULL;
  temp->next = NULL;
  //Copying the nodes.
  while(counter < end_index){
    counter++;
    temp->data = node->data;
    temp->next = malloc(sizeof(output_map_index));
    temp->next->previous = temp;
    temp = temp->next;
    node = node->next;
  }
  //Copying the last node.
  temp->next = NULL;
  temp->data = node->data;
  temp = go_up_index(temp);
  return temp;
}


//Function to slice a map.
output_map_letter * slice_map_letter(output_map_letter * node, bool self, int no_of_arguments, ...) {
  if(node == NULL) {
    printf("Cannot slice the map cause the node is null.\n");
    return NULL;
  }
  node = go_up_letter(node);
  va_list arguments;
  long long int start_index = 0LL;
  long long int length = map_length_letter(node);
  long long int end_index = length-1LL;
  long long int counter  = 0LL;
  output_map_letter *temp = NULL, *tmp = NULL;

  va_start(arguments, no_of_arguments);
  //Checking the no of arguments and setting variables according.
  if(no_of_arguments % 2 != 0){
    printf("There should be two index for slices.\n");
    return NULL;
  }
  while(no_of_arguments/2 > 0){
    //Fetching the indices for slicing.
    start_index = va_arg(arguments, long long int);
    end_index = va_arg(arguments, long long int);
    if(end_index > length-1LL) end_index = length-1LL;

    //Checking whether the starting index is greater than node length.
    if(start_index >= length){
      return NULL;
    }
    //Skipping till the start index.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
    if(temp != NULL){
      tmp = copy_map_letter(node, true, 2, start_index, end_index);
      tmp->previous = temp;
      temp->next = tmp;
    } else {
      temp = copy_map_letter(node, true, 2, start_index, end_index);
    }
    temp = go_down_letter(temp);
    no_of_arguments -= 2;
    counter = 0;
  }
  //Delete the original if the if slicing to original map is prefered.
  if(self == true){
    delete_map_letter(node);
  }

  va_end(arguments);

  return temp;
}

//Function to slice a map.
output_map_index * slice_map_index(output_map_index * node, bool self, int no_of_arguments, ...) {
  if(node == NULL) {
    printf("Cannot slice the map cause the node is null.\n");
    return NULL;
  }
  node = go_up_index(node);
  va_list arguments;
  long long int start_index = 0LL;
  long long int length = map_length_index(node);
  long long int end_index = length-1LL;
  long long int counter  = 0LL;
  output_map_index *temp = NULL, *tmp = NULL;

  va_start(arguments, no_of_arguments);
  //Checking the no of arguments and setting variables according.
  if(no_of_arguments % 2 != 0){
    printf("There should be two index for slices.\n");
    return NULL;
  }
  while(no_of_arguments/2 > 0){
    //Fetching the indices for slicing.
    start_index = va_arg(arguments, long long int);
    end_index = va_arg(arguments, long long int);
    if(end_index > length-1LL) end_index = length-1LL;

    //Checking whether the starting index is greater than node length.
    if(start_index >= length){
      return NULL;
    }
    //Skipping till the start index.
    while(counter < start_index){
      node = node->next;
      counter++;
    }
    if(temp != NULL){
      tmp = copy_map_index(node, true, 2, start_index, end_index);
      tmp->previous = temp;
      temp->next = tmp;
    } else {
      temp = copy_map_index(node, true, 2, start_index, end_index);
    }
    temp = go_down_index(temp);
    no_of_arguments -= 2;
    counter = 0;
  }
  //Delete the original if the if slicing to original map is prefered.
  if(self == true){
    delete_map_index(node);
  }

  va_end(arguments);

  return temp;
}

//Function to re-initialize all the variable.
void re_initialize_outputmap_variables() {
  map_contains_letter_position = 0LL;
  map_length_last_call = 0LL;
}

//Function to reposition a node.
output_map_letter * re_position_letter_node(
  output_map_letter * node, long long int old_position, long long int new_position) {
    //Checking whether the given parameters are valid.
    if(node == NULL) {
      printf("Cannot re-position the node cause given the node is null.\n");
      return NULL;
    }
    if(map_length_letter(node) <= new_position) {
      printf("The new position is greater than the length of the map.\n");
      return NULL;
    }
    if(map_length_last_call <= old_position) {
      printf("The old position is greater than the length of the map.\n");
      return NULL;
    }
    if(old_position != new_position) {
      node = go_up_letter(node);
      long long int loop_variable = 0LL;
      output_map_letter * temp = NULL;
      while(loop_variable < old_position) {
        node = node->next;
        loop_variable++;
      }
      temp = node;
      if(node->previous == NULL) {
        node->next->previous = node->previous;
        node = node->next;
      } else if(node->next == NULL) {
        node->previous->next = node->next;
        node = go_up_letter(node->previous);
      } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        node = go_up_letter(node->previous);
      }

      loop_variable = 0LL;
      while(loop_variable < new_position-1LL) {
        node = node->next;
        loop_variable++;
      }
      //This insertion is based on the algorithm requirement.
      temp->next = node->next;
      node->next = temp;
      temp->previous = node;
      return node;
    } else {
      printf("The old and new position cannot be same\n");
      return node;
    }
}
