/******************************************************************************
*Student Author: Alex Dinkelacker
*University of California, Santa Barbara
*Electrical and Computer Engineering
***************************************
*This project is the first assessment of the course. It covers basic C programming and is focused towards a "brush-up" on the students knowledge of C programming.
*****************************************************************************/

/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @stats.c 
 * C file for first assessment
 *
 * C file that contains main and function calls. 
 *
 * @author Alex Dinkelacker
 * @date 12/31/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  char sort_dir = "reverse order";
  /* Statistics and Printing Functions Go Here */

  //Show what the array looks like prior to sorting 
  printf("Array before sorting is: \n");
  print_array(&test, SIZE);
  //Show what the array looks like after sorting 
  printf("Array after sorting is: \n");
  sort_array(&test, SIZE, sort_dir);
  //The array is now sorted --> test = {2, 2, 3, 5, ...
  print_statistics(&test, SIZE); 
}

/* Add other Implementation File Code Here */
