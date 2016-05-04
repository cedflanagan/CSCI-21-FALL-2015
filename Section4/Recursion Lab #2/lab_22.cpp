/*
 * Name        : lab_22.cpp
 * Author      : Ciaran Flanagan / Russell Powell 
 * Description : Recursive Functions
 */

#include "lab_22.h"

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
 */
unsigned int Factorial(unsigned int value)
{
    unsigned int total = value;
    
    if(value == 0)
    {
        total = 1;
    }
    
    if(value > 1)
    {
        total = total * Factorial(value - 1);
    }
    
    return total;
}

/*
 * Return a specified value in a Fibonacci sequence. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int Fibonacci(unsigned int fib_value)
{
    if(fib_value < 2)
    {
        return fib_value;
    }
    
    else
    {
        return Fibonacci(fib_value - 1) + Fibonacci(fib_value - 2);
    }
}

/*
 * Test a single word to see if it is a palindrome. The word must be all in the same case
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool WordIsPalindrome(string word)
{
    if(word.length() > 1)
    {
    
        if(word[0] == word[word.length() - 1])
        {
            string new_word = word.substr(1, word.length() - 2);
            
            WordIsPalindrome(new_word);
        }
        
        else
        {
            return false;
        }
    }
    return true;
}

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going forward to the end of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string ArrayForwardsAsString(int array[], unsigned int start,
                             unsigned int size)
{
    if(start >= size)
    {
        return "";
    }
    
    stringstream ss;
    
    ss << array[start];
    
    ss << " ";
    
    if(start + 1 < size)
    {
        ss << ArrayForwardsAsString(array, start +1, size);
    }
    
    return ss.str();
}

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going backward to the beginning of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string ArrayBackwardsAsString(int array[], int start,
                             unsigned int size)
{
    if(start < 0)
    {
        return "";
    }
    
    stringstream ss;
    
    ss << array[start];
    
    ss << " ";
    
    if(start > 0)
    {
        ss << ArrayBackwardsAsString(array, start -1, size);
    }
    
    return ss.str();
}

/*
int main()
{
    int array_[5] = {1,2,3,4,5};
    
    cout << ArrayBackwardsAsString(array_, 2, 5) << endl;
    
    cout << ArrayForwardsAsString(array_, 2, 5) << endl;
    
    cout << WordIsPalindrome("racecar") << endl;
    cout << WordIsPalindrome("butter") << endl;
    cout << Factorial(5) << endl; 
    cout << Fibonacci(7) << endl;;
}
*/