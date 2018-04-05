/**
* @file conversion.h
* @brief This file is used to declare the functions used to conver data from
* one form to another.
* @author Andrew Kuklinski and Mason Darveaux
* @date 9/30/2017
**/


#include <stdio.h>
#include <stdint.h>

#ifndef conversion_h_
#define conversion_h_

/*standard interger type to ASCII string  conversion.  Number to convert
  is passed in as signed 32 bit interger and supports bases 2 to 16. USe the pointer provided to copy the new string to.  Returns pointer to the converted data*/
uint8_t* my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/*Converts data from ASCII represented tring into an interger type.*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/*Convert an array of data in memory from big endian to little endian representation.*/
int8_t big_to_little32(uint32_t * data, uint32_t length);

/*Convert an array of data in memory from little endian to big endian representation*/
int8_t little_to_big32(uint32_t * data, uint32_t length);


#endif
