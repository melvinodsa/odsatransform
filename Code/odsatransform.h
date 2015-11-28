/** \file odsatransform.h
 *  \headerfile odsatransform
 *
 *  \brief This contains the prototypes for the odsa transform;
 *  global variables and required functions.
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug Cannot support anything other than ASCII.
 */
#ifndef _ODSATRANSFORM_H_
#define _ODSATRANSFORM_H_

/**
 * \defgroup Forward-Transform ODSA Forward Transform
 * \brief Functions used in forward transform
 * @{
 */

/*! \var extern input_data in_data
 *  \brief Variable holding the input data from the source to be transformed.
 */
extern input_data in_data;

/*! \fn void read_input_file(FILE *file)
 *  \brief A function to read data from input source. It will store the data from input source to in_data
 *  \param file The FILE variable of the input source
 *  \return void
 */
void read_input_file(FILE *file);

/*! \fn void delete_data(input_data data)
 *  \brief A function to delete a input_data variable
 *  \param data The input_data to be deleted
 *  \return void
 */
void delete_data(input_data data);

/*! \fn void delete_input_data()
 *  \brief A function to delete the global variable in_data
 *  \return void
 */
void delete_input_data();

/*! \fn char * iteration_transform(char * data, FILE *file)
 *  \brief A function to for doing the forward odsa transform for a single iteration
 *  \param data The input data to on which the transform has to be performed
 *  \param file The to which transform output of each iteration to be written
 *  \return char *
 */
char * iteration_transform(char * data, FILE *file);

/*! \fn long long int get_input_file_size()
 *  \brief A function to get the size of the input source file which has to be transformed.
 *  \return long long int The size of the input source
 */
long long int get_input_file_size();

/*! \fn void transform_data(const char *output_file)
 *  \brief A function to the available data from in_data variable and write into a
 * file, the transformed data.
 *  \param output_file The input_data to be deleted
 *  \return void
 */
void transform_data(const char *output_file);

/**@}*/

/**
 * \defgroup Reverse-Transform ODSA Reverse Transform
 * \brief Functions used in reverse transform
 * @{
 */

/*! \fn output_map_letter * elloborate(output_map_letter * letter, output_map_index * index)
 *  \brief A function to elloborate the the letter_output_map from transform data
 *  \param letter The letter_output_map with which elaboration has to be performed
 *  \param index The index_output_map with which elaboration has to be performed
 *  \return output_map_letter * The elaborated output
 */
output_map_letter * elloborate(output_map_letter * letter, output_map_index * index);

/*! \fn output_map_letter * reverse_jumps(
  output_map_letter * letter, output_map_index * index, output_map_letter * output)
 *  \brief A function to perform reverse jumps in the elaborated output text
 *  \param letter The letter_jump_map with which jumps has to be performed
 *  \param index The index_jump_map with which jumps has to be performed
 *  \param output The outputon which jumps has to be performed
 *  \return output_map_letter * The output which has done reverse mapping jumps
 */
output_map_letter * reverse_jumps(
  output_map_letter * letter, output_map_index * index, output_map_letter * output);

/*! \fn reverse_transform_data(FILE *input_file, const char *output_file, const char *output_status)
 *  \brief A function to perform reverse transform
 *  \param input_file The input file from which contains the transformation
 *  \param output_file The name of the output file to which the output has to be written
 *  \param output_status The name of the output file to which the status of the output has to be written
 *  \return void
 */
void reverse_transform_data(FILE *input_file, const char *output_file, const char *output_status);

/**@}*/

/*! \fn re_initialize_transform_variables()
 *  \brief A function to re initialize the global variables in odsatransform library
 *
 *  \note
 *  It does not re-initialize current_size or size.
 *  \return void
 */
void re_initialize_transform_variables();

#endif
