/*
 * Name        : sorting.cpp
 * Author      : Ciaran Flanagan
 * Description : Working with Insertion and Shell Sort
 */
 
#include "sorting.h"

// CODE HERE -- FUNCTION DEFINITIONS

void SwapValues(int &value_1, int &value_2)
{
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER)
  {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
  
  int temp = value_1;
  
  value_1 = value_2;
  value_2 = temp;
}

/*
 * Apply the bubble sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int BubbleSort(int the_array[], unsigned int size)
{
    int passes = 0;
    
    for(unsigned int i = size - 1; i > 0; i--)
    {
        for(unsigned int j = 0; j < i; j++)
        {
            if(the_array[j] > the_array[j+1])
            {
                SwapValues(the_array[j], the_array[j+1]);
            }
        }
        
        passes ++;
    }
    
    return passes;
}

/*
 * Apply the optimized bubble sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int OptimizedBubbleSort(int the_array[], unsigned int size)
{
    int passes = 0;
    
    for(unsigned int i = size - 1; i > 0; i--)
    {
        bool sorted = true;
        
        for(unsigned int j = 0; j < i; j++)
        {
            if(the_array[j] > the_array[j+1])
            {
                SwapValues(the_array[j], the_array[j+1]);
                sorted = false;
            }
        }
        
        passes ++;
        
        if(sorted)
        {
            break;
        }
    }
    
    return passes;
}

/*
 * Apply the selection sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int SelectionSort(int the_array[], unsigned int size)
{
    int passes = 0;
    
    for(unsigned int i = 0; i < size - 1; i++)
    {
        int space = i;
        
        for(unsigned int j = i + 1; j < size; j++)
        {
            if(the_array[j] < the_array[space])
            {
                space = j;
            }
        }
        
        SwapValues(the_array[i], the_array[space]);
        
        passes ++;
    }
    
    return passes;
}

/*
 * Apply the insertion sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int InsertionSort(int the_array[], unsigned int size)
{
    int passes = 0;
    
    for(unsigned int i = 1; i < size; i++)
    {
        for(unsigned int j = i; j > 0; j--)
        {
            if(the_array[j] < the_array[j-1])
            {
                SwapValues(the_array[j], the_array[j-1]);
            }
            
            else
            {
                break;
            }
        }
        
        passes ++;
    }
    
    return passes;
}

/*
 * Apply the shell sort algorithm to sort an array of integers.
 * NOTE: At the end of each iteration of the for loop you will need to call
 *       DisplayArray(the_array);
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int ShellSort(int the_array[], unsigned int size)
{
    int passes = 0;
    
    for(unsigned int h = size/2 ; h >= 1; h = h/2)
    {
        for(unsigned int i = h; i < size; i++)
        {
            for(unsigned int j = i; j >= h; j -= h)
            {
                if(the_array[j] < the_array[j-h])
                {
                    SwapValues(the_array[j], the_array[j-h]);
                }
                
                else
                {
                    break;
                }
            }
            
           // DisplayArray(the_array);
        }
        
        passes ++;
    }
    
    return passes;
}


