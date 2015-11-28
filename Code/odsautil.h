/** \file odsautil.h
 *  \headerfile odsautil
 *
 *  \brief This contains the prototypes for the odsa engine;
 *  constants, global variables and other structs.
 *
 *  \author Melvin Davis (melvinodsa@gmail.com)
 *  \bug No known bugs.
 */
#ifndef _ODSAUTIL_H_
#define _ODSAUTIL_H_

/*! \var extern int MAX_JUMP_LENGTH
 *  \brief Maximum no. of jumps allowed in an iteration.
 */
extern int MAX_JUMP_LENGTH;

/*! \typedef bool
 *  \brief Enum for boolean data type
 */
typedef enum {
  false,    /**< enum value 0 */
  true      /**< enum value 1 */
}bool;

/*! \typedef reading_status
 *  \brief Enum for the status while reading from transform file.
 */
typedef enum {
  LETTER_OUTPUT,   /**< state when letter_output_map is read from transform file */
  INDEX_OUTPUT,    /**< state when index_output_map is read from transform file */
  LETTER_JUMP,     /**< state when letter_jump_map is read from transform file */
  INDEX_JUMP       /**< state when index_jump_map is read from transform file */
} reading_status;


/*! \addtogroup Output-Map
*  @{
*/

/*! \struct output_map_l
 *  \brief Structure to hold the letter of output map
 *  \typedef output_map_letter
 *  \brief Typedef for output_map_l
 *
 */
typedef struct output_map_l{
  char data;        /**<  Variable to hold the data of map */
  struct output_map_l * next;  /**<  Variable to hold address of next node */
  struct output_map_l * previous;  /**<  Variable to hold address of previous node */
} output_map_letter;

/*! \typedef output_map_index
 *  \brief Typedef for output_map_i.
 *  \struct output_map_i
 *  \brief Structure to hold the index of output map.
 */
typedef struct output_map_i{
  long long int data;  /**<  Variable to hold the data of map */
  struct output_map_i * next; /**<  Variable to hold address of next node */
  struct output_map_i * previous; /**<  Variable to hold address of previous node */
} output_map_index;


/**@}*/
/*! \typedef input_data
 *  \brief Typedef for input_data_structure.
 *  \struct input_data_structure
 *  \brief Structure to hold the input data.
 *
 */
typedef struct input_data_structure {
  char * input_text; /**<  Variable to hold the input text */
  output_map_letter * letter_jump_map; /**<  Variable to hold letters of jump map */
  output_map_index * index_jump_map;  /**<  Variable to hold the index of jump map */
  output_map_letter * letter_output_map;  /**<  Variable to hold the letter of output map */
  output_map_index * index_output_map;  /**<  Variable to hold the index of output map */
  long long int last_buffer_length;  /**<  Variable to hold the length of last countinous streak */
  bool just_appended;  /**<  Variable to hold the just appended or not bool */
}input_data;

#endif
