/*
 * Name        : lab_3.cpp
 * Author      : Ciaran Flanagan / April Browne
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
string Goldilocks(string item, int number) {
  // CODE HERE
  
  string output;
  
  if (item == "porridge")
  {
    switch (number)
    {
      case 1: output = "This porridge is too hot.";
      break;
      case 2: output = "This porridge is too cold.";
      break;
      case 3: output = "This porridge is just right.";
      break;
      default: output = "This porridge is just right.";
      break;
    }
  }
  
  else if (item == "chair")
  {
    switch (number)
    {
      case 1: output = "This chair is too big.";
      break;
      case 2: output = "This chair is too small.";
      break;
      case 3: output = "This chair is just right.";
      break;
      default: output = "This chair is just right.";
      break;
    }
  }
  
  else
  {
    switch (number)
    {
      case 1: output = "This bed is too hard.";
      break;
      case 2: output = "This bed is too soft.";
      break;
      case 3: output = "This bed is just right.";
      break;
      default: output = "This bed is just right.";
      break;
    }
  }
  
  return output;
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
int RockScissorPaper(char player_one, char player_two) {
  // YOU MUST USE A SWITCH IN THIS FUNCTION
  // CODE HERE
  
  int outcome = 0;
  
  /*
  if (islower(player_one))
  {
    player_one = ToUpper(player_one)
  }
  
  if (islower(player_two))
  {
    player_two = ToUpper(player_two)
  }
  */
  
  switch (player_one)
  {
    case 'R':
    case 'r':
      switch (player_two)
      {
        case 'R':
        case 'r':
          outcome = 3;
          break;
        case 'S':
        case 's':
          outcome = 1;
          break;
        case 'P':
        case 'p':
          outcome = 2;
          break;
        default: 
          outcome = 0;
          break;
      }
      break;
    case 'S':
    case 's':
      switch (player_two)
      {
        case 'R':
        case 'r':
          outcome = 2;
          break;
        case 'S':
        case 's':
          outcome = 3;
          break;
        case 'P':
        case 'p':
          outcome = 1;
          break;
        default:
          outcome = 0;
          break;
      }
      break;
    case 'P':
    case 'p':
      switch (player_two)
      {
        case 'R':
        case 'r':
          outcome = 1;
          break;
        case 'S':
        case 's':
          outcome = 2;
          break;
        case 'P':
        case 'p':
          outcome = 3;
          break;
        default:
          outcome = 0;
          break;
      }
      break;
    default: 
      outcome = 0;
      break;
  }
  
  return outcome;
  
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  // CODE HERE
  
  string lower_string;
  
  int how_long = input.length();
  
  for (int i = 0; i < how_long; i++)
  {
      lower_string[i] = tolower(input[i]);
  }
  
  return lower_string;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  // CODE HERE
    
  string upper_string;
  
  int how_long = input.length();
  
  for (int i = 0; i < how_long; i++)
  {
    upper_string[i] = toupper(input[i]);
  }
  
  return upper_string;
}

/*
int main()
{
  cout << "Goldilocks tried the second Porridge: " << Goldilocks("porridge", 2) << endl;
  
  cout << "Goldilocks tried the first Chair: " << Goldilocks("chair", 1) << endl;
  
  cout << "Goldilocks tried the third Bed: " << Goldilocks("Bed", 3) << endl;

  cout << "Goldilocks tried the twelfth Coatrack: " << Goldilocks("coatrack", 12) << endl;
  
  cout << " Rock and Scissors are thrown: Player " << RockScissorPaper('R', 's') << " wins." << endl;
  
  cout << " Paper and Scissors are thrown: Player " << RockScissorPaper('p', 'S') << " wins." << endl;

  cout << " Paper and Paper are thrown: Player " << RockScissorPaper('P', 'p') << " wins." << endl;

}
/*