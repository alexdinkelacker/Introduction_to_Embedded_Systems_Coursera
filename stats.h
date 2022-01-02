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
 * @stats.h 
 * header file for first assessment
 *
 * Header file that contains all function declarations and 
 * function implementations to be used in the first assessment. 
 *
 * @author Alex Dinkelacker
 * @date 12/31/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
------------------------------------------
--------Function Declarations-------------
------------------------------------------
 */

/**
 * @print_statistics() - prints stats: minimum, maximum, mean, and median
 *
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <void>
 */
void print_statistics(unsigned char *data, unsigned int length); 

/**
 * @print_array() - prints array to the screen
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <void>
 */
void print_array(unsigned char *data, unsigned int length); 

/**
 * @find_median() - finds and returns median value
 *
 * Given an array of data and a length, returns the median value
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <float> <median value of the array>
 */
float find_median(unsigned char *data, unsigned int length);

/**
 * @find_mean() - finds and returns mean value
 *
 * Given an array of data and a length, returns the mean.
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <float> <mean value of the array> 
 */
float find_mean(unsigned char *data, unsigned int length);

/**
 * @find_maximum() - finds and returns max value
 *
 * Given an array of data and a length, returns the maximum.
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <float> <maximum value of array>
 */
float find_maximum(unsigned char *data, unsigned int length); 

/*---------------find_minimum()--------------- 
Given an array of data and a length, returns the minimum
*/
/**
 * @find_minimumm() - finds and returns min value
 *
 * Given an array of data and a length, returns the minimum.
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 *
 * @return <float> <minimum value of array>
 */
float find_minimum(unsigned char *data, unsigned int length); 

/**
 * @sort_array() sorts the array from largest to smallest
 *
 *Given an array of data and a length, sorts the array from largest to smallest.  
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param <unsigned char *data> <unsigned char pointer directed at incoming unsigned char array in memory>
 * @param <unsigned int length> <a known unsigned int length of the incoming char array>
 * @param <char dir> <the direction in which the array should be sorted, 'r' for reverse and 'f' for forward>
 *
 * @return <void>
 */
void sort_array(unsigned char *data, unsigned int length, char dir); 


/*----------------------------------------
--------Function Implementations----------
------------------------------------------*/
void print_statistics(unsigned char *data, unsigned int length, char dir){
    printf("The min is %0.2f\n", find_minimum(data, length));
    printf("The max is %0.2f\n", find_maximum(data, length));
    printf("The mean is %0.2f\n", find_mean(data, length));
    printf("The median is %0.2f\n", find_median(data, length));

}


void print_array(unsigned char *data, unsigned int length){
    //Iterate through the array and print out each element
    for(int i = 0; i < length; i++){
        if (i < (length-1)) //--------------if you're not at the end then add a comma 
            printf("%4i, ", *(data+i));
        else                                //--------------if you're at the end of the array then drop the last comma
            printf("%4i \n", *(data+i));
    
        if (((i+1) % 8 == 0)&&(i != 0))//---for each column of 8 put a \n
            printf("\n");
    }
} 

float find_median(unsigned char *data, unsigned int length){
    //sort_array gets called in main prior to this, so the array will already be sorted
    //however - one would want to sort first  
    //if length == odd  -> divide by 2 and round up to get the position of the median number 
    //if length == even -> divide by 2 and go to that number in that position and average it with the number in                                 the next higher position 
    float median = 0; 
    
    if (length%2 == 0)//even 
        median = (float)(*(data+length/2-1)+*(data+length/2))/2;
    
    //we know the length is even so I will not consider the odd case
    
    return median; 
    
    
}

float find_mean(unsigned char *data, unsigned int length){
    float mean = 0; 
    float sum = 0; 
    for(int i = 0; i < length; i++)
        sum = sum + *(data+i); 
    return mean = sum/length; 
}

float find_maximum(unsigned char *data, unsigned int length){
    float max = *data;   
    for(int i = 1; i < length; i++)
         if(*(data+i) > max)
            max = *(data+i); 
    return max; 
}

float find_minimum(unsigned char *data, unsigned int length){
    float min = *data;   
    for(int i = 1; i < length; i++)
         if(*(data+i) < min)
            min = *(data+i); 
    return min; 
}

void sort_array(unsigned char *data, unsigned int length, char dir){
    //bubble-sort
    
    while(1){
        int swapped = 0; 
        
        for(int i = 0; i < length - 1; i++){
        
            if(dir == 'r'){
                if (*(data+i) < *(data+i+1)){
                    int temp = *(data+i);
                    *(data+i) = *(data+i+1);
                    *(data+i+1) = temp; 
                    swapped = 1; 
                }
            }else{  
                if (*(data+i) > *(data+i+1)){
                    int temp = *(data+i);
                    *(data+i) = *(data+i+1);
                    *(data+i+1) = temp; 
                    swapped = 1; 
                }
            }
        }
        
        if(swapped == 0){
            break; 
        }   
    }
    print_array(data, length); 
    
}



/*******************SAVE************************** 
/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 **************************************************/


#endif /* __STATS_H__ */
