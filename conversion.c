/**
* @file conversion.c
* @brief This file is used to convert data from one format to another in
* project 1. The functions convert data from big to little endian and vice
* versa, as well as convert integers to ascii values and vice versa
* @author Andrew Kuklinski and Mason Darveaux
* @date 9/30/2017
**/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "conversion.h"
#include "memory.h"
#include <math.h>

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
    if(data == NULL)
    {
      return 1;
    }
  //masks out each indivual byte of data into variables
  uint32_t original1 = *data & 0x000000ff;
  uint32_t original2 = *data & 0x0000ff00;
  uint32_t original3 = *data & 0x00ff0000;
  uint32_t original4 = *data & 0xff000000;

  //shifts each byte of data to its new position
  uint32_t newDigit1 = original1 << 24;
  uint32_t newDigit2 = original2 << 8;
  uint32_t newDigit3 = original3 >> 8;
  uint32_t newDigit4 = original4 >> 24;

  //stores the shifted data in the original location
  *data = newDigit1 | newDigit2 | newDigit3 | newDigit4;

  //verifies the process occurred correctly
  if(((original1<<24)==newDigit1)&((original2<<8)==newDigit2)&
     ((original3>>8)==newDigit3)&((original4>>24)==newDigit4))
    {
      return 0;
    }
  else
    {
      return 1;
    }
}


int8_t big_to_little32(uint32_t * data, uint32_t length)
{

  if(data == NULL)
    {
      return 1;
    }
  //masks out each indivual byte of data into variables
  uint32_t original1 = *data & 0xff000000;
  uint32_t original2 = *data & 0x00ff0000;
  uint32_t original3 = *data & 0x0000ff00;
  uint32_t original4 = *data & 0x000000ff;

  //shifts each byte of data to its new position
  uint32_t newDigit1 = original1 >> 24;
  uint32_t newDigit2 = original2 >> 8;
  uint32_t newDigit3 = original3 << 8;
  uint32_t newDigit4 = original4 << 24;

  //stores the shifted data in the original location
  *data = newDigit1 | newDigit2 | newDigit3 | newDigit4;

  //verifies the proccess occurred correctly
  if(((original1>>24)==newDigit1)&((original2>>8)==newDigit2)&
     ((original3<<8)==newDigit3)&((original4<<24)==newDigit4))
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

uint8_t* my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    //creates variables to store the remainder of the modulo operation
    //and keep track of the length of the ascii string generated
    int rem;
    int length=0;

    //loop continues to divide the data by the base value and perform the
    //modulo operation using the base value until the data equals 0
    if (data==0)
        {
            *ptr = 48;
        }
    else
    {
        while(data!=0)
    {
        rem =data%base;
        data = data/base;

        //converts digits A-F to ascii values
        if(rem>9)
        {
            *ptr = (uint8_t) rem+55;
        }

        else
        //converts digits 0-9 to ascii values
        {
            *ptr=rem+48;
        }

        ptr++;
        length++;
    }
    //restores the ptr to its original value
    ptr = ptr-length;


    //reverse the digits to be stored in the correct order
    my_reverse(ptr, length);
    }

    return ptr;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{

    uint32_t j =0;
    int8_t i=0;
    int8_t dig=0;
    int32_t number=0;
    int32_t mult =0;

    for(i=digits-1; i>=0;i--)
    {
        dig = *(ptr+i);

        if(65<= dig && dig <= 70)
        {
        dig =dig-55;
        }

        else
        {
        dig = dig-48;
        }

        mult = (int32_t) pow((double) base, (double) j);
        number+=dig*mult;

        j++;
    }

    return number;
}
