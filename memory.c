/**
* @file memory.c
* @brief This file is used to manipulate data in memory and allocate
* space in memory
* @author Andrew Kuklinski and Mason Darveaux
* @date 9/30/2017
**/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{

  int i;
  //checking for invalid NULL pointers
  if(src == NULL)
    {
      return (void*)NULL;
    }
  //sets a number of bytes (defined by length) in memory equal to value, starting
  //the src address
  for(i=0; i<length; i++)
  {
    *src = value;
    src++;
  }
  // resets src pointer to original value
  return ((int8_t*) src-length);
}


uint8_t * my_memzero(uint8_t * src, size_t length)
{
    int i;
  //checking for invalid NULL pointers
  if(src == NULL)
    {
      return (void*)NULL;
    }
  //sets a number of bytes (defined by length) in memory equal to zero, starting
  //at the src address
  for(i=0; i<length; i++)
  {
    *src = 0;
    src++;
  }
  // returns src pointer to original value
  return ((uint8_t*) src-length);
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    int i,j;
  //checking for invalid NULL pointers
  if(src == NULL || dst == NULL)
    {
      return (void*)NULL;
    }

  //defines an array to hold the src data in order to prevent corruption
  uint8_t holdArray[length];
  uint8_t *holdArrayPtr = holdArray;

  //copies src data into the hold array
  for(i=0; i<length; i++)
  {
    *holdArrayPtr = *src;
    src++;
    holdArrayPtr++;
  }

  //resets holdArrayPtr to original value
  holdArrayPtr = holdArray;

  //copies data from hold array into destination
  for(j=0; j<length; j++)
  {
    *dst = *holdArrayPtr;
    dst++;
    holdArrayPtr++;
  }

  //returns destination pointer to original value
  return ((uint8_t*) dst-length);
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{

  int i;
  //copies data directly from source location to destination
  for(i=0; i<length; i++)
  {
    *dst = *src;
    src++;
    dst++;
  }

  //resets dst pointer to original value
  return (dst - length);
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{

  if(src == NULL)
  {
    return (void*)NULL;
  }
  //defines pointers to the beginning and end of array of data
  uint8_t *ptrHead = src;
  uint8_t *ptrTail = src + (length-1);

  //defines intermediate variable to store data when swapping bytes
  uint8_t intermediate = 0;


  if(ptrHead == (ptrTail-1))
      {
        intermediate = *ptrHead;
        *ptrHead = *ptrTail;
        *ptrTail = intermediate;
      }

  //will continue to loop until head and tail pointers are equal,
  //or they are adjacent

  while(!((ptrHead == ptrTail) || (ptrHead == (ptrTail -1))))
  {
    //swaps the bytes of the array
    intermediate = *ptrHead;
    *ptrHead = *ptrTail;
    *ptrTail = intermediate;
    ptrHead++;
    ptrTail--;

    // if head and tail pointers are adjacent, perform one additional swap before
    // exiting the loop
    if(ptrHead == (ptrTail-1))
    {
      intermediate = *ptrHead;
      *ptrHead = *ptrTail;
      *ptrTail = intermediate;
    }
  }
  return src;
}

int32_t * reserve_words(size_t length)
{
  //defines a pointer to be used to return the address of the allocated memory
  int32_t * reservePtr;

  //allocates a number of words in memory defined by the length value
  reservePtr = (int32_t *) malloc((sizeof(size_t)*length));

  //malloc returns a 0 if it fails
  if(reservePtr == 0)
  {
    return NULL;
  }
  return reservePtr;
}

void free_words(uint32_t * src)
{
  //frees memory previously allocated using malloc
  free(src);
}
