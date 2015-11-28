/** \file odsaoutputmap.h
 *  \headerfile odsaoutputmap
 *
 *  \brief This contains the prototypes for the odsa output maps;
 *  global variables and required functions.
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug Cannot support anything other than ASCII.
 */
#ifndef _ODSAOUTPUTMAP_H_
#define _ODSAOUTPUTMAP_H_

/**
 * \defgroup Output-Map ODSA Output Maps
 * \brief Functions required for the odsa output maps
 * @{
 */

/*! \var extern long long int map_contains_letter_position
 *  \brief Variable holding the position of the letter found in the
  output_map_letter that was queried through contains_letter()
 *   that was searched last
 */
extern long long int map_contains_letter_position;

/*! \var extern long long int map_length_last_call
 *  \brief Variable holding the length of the output_map (index/letter) whose
  length wasqueried last through map_length_letter() or map_length_index()
 */
extern long long int map_length_last_call;

 /*! \fn output_map_index * append_index_at(long long int data, output_map_index * node, long long int position)
  *  \brief A function to append data to a output_map_index at a particular position
  *  \param data Variable holding the data to be appended
  *  \param node Variable holding the node in which data has to be inserted
  *  \param position Variable holding the position at which the data is to be inserted
  *  \return output_map_index *
  */
output_map_index * append_index_at(long long int data, output_map_index * node, long long int position);

/*! \fn output_map_index * append_index(long long int data, output_map_index * node)
 *  \brief A function to append data to a output_map_index at the current node
 *  \param data Variable holding the data to be appended
 *  \param node Variable holding the node in which data has to be inserted
 *  \return output_map_index *
 */
output_map_index * append_index(long long int data, output_map_index * node);

/*! \fn output_map_index * go_down_index(output_map_index * node)
 *  \brief A function to go down to the last node of a output_map_index
 *  \param node Variable holding the map of which last node has to be obtained
 *  \return output_map_index *
 */
output_map_index * go_down_index(output_map_index * node);

/*! \fn output_map_index * go_up_index(output_map_index * node)
 *  \brief A function to go up to the last node of a output_map_index
 *  \param node Variable holding the map of which last node has to be obtained
 *  \return output_map_index *
 */
output_map_index * go_up_index(output_map_index * node);

/*! \fn void print_map_index(output_map_index * node)
 *  \brief A function to print the nodes of a output_map_index to the standard output
 *  \param node Variable holding the map to be printed
 *  \return void
 */
void print_map_index(output_map_index * node);

/*! \fn void print_map_index_to_file(output_map_index * node, FILE *file)
 *  \brief A function to print the nodes of a output_map_index to the given file
 *  \param node Variable holding the map to be printed
 *  \param file FILE variable holding the to be which the node has to be written
 *  \return void
 */
void print_map_index_to_file(output_map_index * node, FILE *file);

/*! \fn void print_map_index_to_file_reverse(output_map_index * node, FILE *file)
 *  \brief A function to print the nodes of a output_map_index to the given file
 *  in reverse order.
 *  \param node Variable holding the map to be printed
 *  \param file FILE variable holding the to be which the node has to be written
 *  \return void
 */
void print_map_index_to_file_reverse(output_map_index * node, FILE *file);

/*! \fn void delete_map_index(output_map_index * node)
 *  \brief A function to delete the nodes of a output_map_index and free memory
 *  \param node Variable holding the map to be deleted
 *  \return void
 */
void delete_map_index(output_map_index * node);

/*! \fn long long int map_length_index(output_map_index * node)
 *  \brief A function to get the length of the output_map_index. The value is
 *  also stored in map_length_last_call after every call
 *  \param node Variable holding the map to be whose length has to be found out
 *  \return long long int
 */
long long int map_length_index(output_map_index * node);

/*! \fn output_map_index * copy_map_index(output_map_index * node, bool verification, int no_of_arguments, ...)
 *  \brief A function to copy the nodes of a output_map_index to a new output_map_index
 *  which it will return
 *
 *  If the verification parameter is true then the indices that are passing are already
 *  and additional verification is not required. So the function will run more faster.
 *  If verification is passed false, then function will evaluate the feasibility
 *  of copying the map and copies it if the indices are with in the limits of lenght
 *  of the map. If no. of arguments is 0 then the entire map will be copied. If its
 *  1 then the map will copied from the nodes starting from the given index parameter
 *  (long long int) which comes after the no_of_arguments parameter as variable
 *  parameter. If no_of_arguments is 2 then the nodes starting from the start index
 *  to the end index will be copied from the map. The start and end index are given
 *  after no_of_arguments parameter as variable parameter in order in that particular case.
 *  \param node Variable holding the map to be copied
 *  \param verification Variable holding the flag whether the verification is required or not
 *  \param no_of_arguments Variable holding the no of arguments to follow after it.
 *   Its value can be 0, 1, 2
 *  \param ... Variable parameters.Its number will be accordance with the no_of_arguments
 *   parameter and of type long long int
 *  \return output_map_index *
 */
output_map_index * copy_map_index(output_map_index * node, bool verification, int no_of_arguments, ...);

/*! \fn output_map_index * slice_map_index(output_map_index * node, bool self, int no_of_arguments, ...)
 *  \brief A function to slice a output_map_index to a new output_map_index or itself
 *
 *  If the self parameter is true then new memory won't be allocated assuming that
 *  the function is returning the new sliced map to itself.
 *  If no. of arguments is 0 then the entire map will be sliced as a single. If its
 *  1 then the map will sliced from the nodes starting from the given index parameter
 *  (long long int) which comes after the no_of_arguments parameter as variable
 *  parameter. If no_of_arguments is 2 then the nodes starting from the start index
 *  to the end index will be in there in the slice of the map. The start and end index are given
 *  after no_of_arguments parameter as variable parameter in order in that particular case.
 *  \param node Variable holding the map to be sliced
 *  \param self Variable holding the flag whether its sliced and stored to itself or not
 *  \param no_of_arguments Variable holding the no of arguments to follow after it.
 *   Its value can be 0, 1, 2
 *  \param ... Variable parameters.Its number will be accordance with the no_of_arguments
 *   parameter and of type long long int
 *  \return output_map_index *
 */
output_map_index * slice_map_index(output_map_index * node, bool self, int no_of_arguments, ...);

/*! \fn output_map_letter * append_letter(char data, output_map_letter * node)
 *  \brief A function to append data to a output_map_letter at the current node
 *  \param data Variable holding the data to be appended
 *  \param node Variable holding the node in which data has to be inserted
 *  \return output_map_letter *
 */
output_map_letter * append_letter(char data, output_map_letter * node);

/*! \fn output_map_letter * append_letter_at(char data, output_map_letter * node, long long int position)
 *  \brief A function to append data to a output_map_letter at a particular position
 *  \param data Variable holding the data to be appended
 *  \param node Variable holding the node in which data has to be inserted
 *  \param position Variable holding the position at which the data is to be inserted
 *  \return output_map_letter *
 */
output_map_letter * append_letter_at(char data, output_map_letter * node, long long int position);

/*! \fn output_map_letter * go_down_letter(output_map_letter * node)
 *  \brief A function to go down to the last node of a output_map_letter
 *  \param node Variable holding the map of which last node has to be obtained
 *  \return output_map_letter *
 */
output_map_letter * go_down_letter(output_map_letter * node);

/*! \fn output_map_letter * go_up_letter(output_map_letter * node)
 *  \brief A function to go up to the last node of a output_map_letter
 *  \param node Variable holding the map of which last node has to be obtained
 *  \return output_map_letter *
 */
output_map_letter * go_up_letter(output_map_letter * node);

/*! \fn void print_map_letter(output_map_letter * node)
 *  \brief A function to print the nodes of a output_map_letter to the standard output
 *  \param node Variable holding the map to be printed
 *  \return void
 */
void print_map_letter(output_map_letter * node);

/*! \fn void print_map_letter_to_file_as_plaintext(output_map_letter * node, FILE *file)
 *  \brief A function to print the nodes of a output_map_letter to the given file
 *  in plain text mode. It is used in the reverse transformation
 *  \param node Variable holding the map to be printed
 *  \param file FILE variable holding the to be which the node has to be written
 *  \return void
 */
void print_map_letter_to_file_as_plaintext(output_map_letter * node, FILE *file);

/*! \fn void print_map_letter_to_file(output_map_letter * node, FILE *file)
 *  \brief A function to print the nodes of a output_map_letter to the given file
 *  \param node Variable holding the map to be printed
 *  \param file FILE variable holding the to be which the node has to be written
 *  \return void
 */
void print_map_letter_to_file(output_map_letter * node, FILE *file);

/*! \fn void print_map_letter_to_file_reverse(output_map_letter * node, FILE *file)
 *  \brief A function to print the nodes of a output_map_letter to the given file
 *  in reverse order.
 *  \param node Variable holding the map to be printed
 *  \param file FILE variable holding the to be which the node has to be written
 *  \return void
 */
void print_map_letter_to_file_reverse(output_map_letter * node, FILE *file);

/*! \fn void delete_map_letter(output_map_letter * node)
 *  \brief A function to delete the nodes of a output_map_letter and free memory
 *  \param node Variable holding the map to be deleted
 *  \return void
 */
void delete_map_letter(output_map_letter * node);

/*! \fn bool contains_letter(char data, output_map_letter * node)
 *  \brief A function to check whether a given data is there in the output_map_letter.
 *  If the value is present in the map its position is
 *  also stored in map_contains_letter_position after every call
 *  \param data Variable holding data to be searched
 *  \param node Variable holding the map to be whose length has to be found out
 *  \return bool
 */
bool contains_letter(char data, output_map_letter * node);

/*! \fn long long int map_length_letter(output_map_letter * node)
 *  \brief A function to get the length of the output_map_letter. The value is
 *  also stored in map_length_last_call after every call
 *  \param node Variable holding the map to be whose length has to be found out
 *  \return long long int
 */
long long int map_length_letter(output_map_letter * node);

/*! \fn output_map_letter * copy_map_letter(output_map_letter * node, bool verification, int no_of_arguments, ...)
 *  \brief A function to copy the nodes of a output_map_letter to a new output_map_letter
 *  which it will return
 *
 *  If the verification parameter is true then the indices that are passing are already
 *  and additional verification is not required. So the function will run more faster.
 *  If verification is passed false, then function will evaluate the feasibility
 *  of copying the map and copies it if the indices are with in the limits of lenght
 *  of the map. If no. of arguments is 0 then the entire map will be copied. If its
 *  1 then the map will copied from the nodes starting from the given index parameter
 *  (long long int) which comes after the no_of_arguments parameter as variable
 *  parameter. If no_of_arguments is 2 then the nodes starting from the start index
 *  to the end index will be copied from the map. The start and end index are given
 *  after no_of_arguments parameter as variable parameter in order in that particular case.
 *  \param node Variable holding the map to be copied
 *  \param verification Variable holding the flag whether the verification is required or not
 *  \param no_of_arguments Variable holding the no of arguments to follow after it.
 *   Its value can be 0, 1, 2
 *  \param ... Variable parameters.Its number will be accordance with the no_of_arguments
 *   parameter and of type long long int
 *  \return output_map_letter *
 */
output_map_letter * copy_map_letter(output_map_letter * node, bool verification, int no_of_arguments, ...);

/*! \fn output_map_letter * slice_map_letter(output_map_letter * node, bool self, int no_of_arguments, ...)
 *  \brief A function to slice a output_map_index to a new output_map_letter or itself
 *
 *  If the self parameter is true then new memory won't be allocated assuming that
 *  the function is returning the new sliced map to itself.
 *  If no. of arguments is 0 then the entire map will be sliced as a single. If its
 *  1 then the map will sliced from the nodes starting from the given index parameter
 *  (long long int) which comes after the no_of_arguments parameter as variable
 *  parameter. If no_of_arguments is 2 then the nodes starting from the start index
 *  to the end index will be in there in the slice of the map. The start and end index are given
 *  after no_of_arguments parameter as variable parameter in order in that particular case.
 *  \param node Variable holding the map to be sliced
 *  \param self Variable holding the flag whether its sliced and stored to itself or not
 *  \param no_of_arguments Variable holding the no of arguments to follow after it.
 *   Its value can be 0, 1, 2
 *  \param ... Variable parameters.Its number will be accordance with the no_of_arguments
 *   parameter and of type long long int
 *  \return output_map_letter *
 */
output_map_letter * slice_map_letter(output_map_letter * node, bool self, int no_of_arguments, ...);

/*! \fn output_map_letter * re_position_letter_node(output_map_letter * node, long long int old_position, long long int new_position)
 *  \brief A function to reposition a particular node from one location to another in a output_map_letter.
 *  \param node Variable holding map in which node has to replaced
 *  \param old_position Variable holding position of the node to be repositioned
 *  \param new_position Variable holding new position to which the node has to be repositioned
 *  \return bool
 */
output_map_letter * re_position_letter_node(
  output_map_letter * node, long long int old_position, long long int new_position);

  /*! \fn re_initialize_outputmap_variables()
   *  \brief A function to re initialize the global variables in odsaoutputmap library
   *  \return void
   */
void re_initialize_outputmap_variables();

  /**@}*/
#endif
