/**
* @file memory.h
* @brief This file is used to declare the functions used to manipulate memory
* for project 1.
* @author Andrew Kuklinski and Mason Darveaux
* @date 9/30/2017
**/


#include <stdio.h>
#include <stdint.h>

#ifndef memory_h_
#define memory_h_

/*Takes in one source and one destination pointer and a length
  of bytes to copy from the sourcelocation to the deistination.
  Copy should occur with no data corruption*/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/*Takes in one souce and one estination pinter and a length to copy from
  the source location tothe destination. Copy should still occur
  if destinataion and source overlap*/
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);

/*Takes a pointer to a source memory location and a length and sets
  all locations of that memory to a given value*/
int8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/*Takes a pinter to a memory lcoation and a length and places zero
  in all of the memory locations.*/
uint8_t * my_memzero(uint8_t * src, size_t length);

/*Takes a pointer to memory location andlength and reverses the
  order of all the bytes.*/
uint8_t * my_reverse(uint8_t * src, size_t length);

/*Takes a number of words and allocates them in dynamic memory*/
int32_t * reserve_words(size_t length);

/*Takes a pointer to an allocated section of dynamic memory
  and frees that section*/
void free_words(uint32_t * src);

#endif
