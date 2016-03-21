/*
 * Name        : lab_14.cpp
 * Author      : Ciaran Flanagan
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
 
#include "lab_14.h"

// CODE HERE -- FUNCTION DEFINITIONS

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size)
{
    int *ptr_array = new int[size];
    
    return ptr_array;
}

/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size)
{
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    
    int sum = 0;
    
    for(unsigned int i = 0; i < array_size; i++)
    {
        sum += the_array[i];
    }
    
    return sum;
}

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size)
{
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    
    int max = the_array[0];
    
    for(unsigned int i = 1; i < array_size; i++)
    {
        if(max < the_array[i])
        {
            max = the_array[i];
        }
    }
    
    return max;
}

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size)
{
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    
    int min = the_array[0];
    
    for(unsigned int i = 1; i < array_size; i++)
    {
        if(min > the_array[i])
        {
            min = the_array[i];
        }
    }
    
    return min;
}