/*
 * Name        : lab_5.cpp
 * Author      : Ciaran Flanagan / April Browne
 * Description : Practicing Functions. Use this file to write your
 *               Function Definitions (what goes below main()).
 */

#include "lab_5.h"

// CODE HERE (FUNCTION DEFINITIONS)


/*
 * Displays "Hello world!" to stdout (cout) (no newline character after)
 */
void Hello()
{
    cout << "Hello world!";
    
    return;
}

/*
 * Displays the string parameter to stdout (no newline character)
 * @param const string& - The string to display to stdout
 */
void PrintMessage(string str_in)
{
    cout << str_in;
    
    return;
}

/*
 * Returns the integer value 42.
 * @return int - The value 42
 */
int GetAnswer()
{
    return 42;
}

/*
 * Returns the larger of the two parameter values. Should work correctly
 * if the values are equivalent (returns either one)
 * @param int - The first value
 * @param int - The second value
 * @return int - The larger of the two values, or either one if they are equal
 */
int FindLarger(int in_one, int in_two)
{
    int larger;
    
    if (in_one > in_two)
    {
        larger = in_one;
    }
    
    else
    {
        larger = in_two;
    }
    
    return larger;
}

/*
 * Return the string "Message: STRING", where STRING is replaced by the value of
 * the first parameter (string). If second parameter (bool) is true, convert
 * first parameter (string) to all uppercase letters before concatenating it
 * with "Message: ". If first parameter is the empty string, return
 * "Message: empty".
 * @param string - A message.
 *               - Defaults to "" (empty string)
 * @param bool - To indicate if we should uppercase letters or not
 *             - Defaults to false
 */
string BuildMessage()
{
    return "Message: empty";
}


//+1 overload
string BuildMessage(string str_in)
{
    string  message = "Message: " + str_in;
    
    return message;
}

//+2 overload
string BuildMessage(string str_in, bool caps)
{
    string message;
    
    if (caps == true)
    {
        int how_long = str_in.length();
        
        for (int i = 0; i < how_long; i++)
        {
            str_in[i] = toupper(str_in[i]);
        }
    }
    
    message = "Message: " + str_in;
    
    return message;
}