/*
 * Name        : lab_1.cpp
 * Author      : Ciaran Flanagan / April Browne
 * Date        : Janurary 27th, 2016
 * Description : Our First Lab of the Semester!
 */
 
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Create a string message based upon whether or not a user has 
 * programming experience.
 * @param hasExperience a char ('y'es or 'n'o) representing whether
 *        or not a user has programming experience
 * @return "Welcome back" when hasExperience is 'y', else "Get ready to
 *         have some fun"
 */
string checkExperience (char hasExperience) 
{
    string response;
  
    if (hasExperience == 'y')
    {
        response = "Welcome back.";
    }
    
    else if (hasExperience == 'n')
    {
        response = "Get ready to have some fun.";
    }
    
    else 
    {
        response = "We'll need to work on following directions.";
    }
    
    return response;
}

/*
 * Create a program based on the comments below
 * @param none
 * @return none
 */
 
void FirstLab() 
{
  // (1) Declare a string variable named first_name
  
  string first_name;
  

  // (2) Declare a character variable named programmed_before and another named
  //     my_character. Initialize both of them to the value 'z'
  
  char programmed_before = 'z';
  //char my_character = 'z';
  

  // (3) Display a welcome message to standard output
  
  cout << "Welcome to Lab 1." << endl;

  // (4) Prompt the user for their first name
  
  cout << "Please enter your first name:" << endl;

  // (5) Read the name from standard input and store in the variable first_name
  
  cin >> first_name;

  // (6) Display the message "Nice to meet you, NAME" where NAME is replaced
  //     with the value of first_name
  
  cout << "Nice to meet you, " << first_name << "." << endl;

  // (7) Ask the user if they have programmed before. Make sure you inform them
  //     that you want the answer as a single character (y/n)
  
  cout << "Have you programmed before? (y/n)" << endl;

  // (8): Read in the answer from standard input and store in the variable
  //      programmed_before

  cin >> programmed_before;

  // (9): Call the function checkExperience appropriately so that the message will display
  
  cout << checkExperience(programmed_before) << endl;

}



int main()
{
  FirstLab();
  return 0;
}