/*
 * Name        : lab_recursion.cpp
 * Author      : Ciaran Flanagan
 * Description : Recursive Functions
 */

#include "lab_recursion.h"

#include <math.h>

// CODE FUNCTION DEFINITIONS HERE

/*
 * UPDATE!!!! to match the requirements
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
stringstream decToBin(int num)
{
	stringstream bin;
	
	if (num > 1) //note this makes the base case num = 0
	{
		bin << decToBin(num/2); //recursive call
	}
	
	bin<<(num%2); //outputs in correct order
	
	return bin;
}

unsigned int binToDec(string num)
{
	stringstream bin;
	bin << num;
	
	int bin_digits = bin.str().length();
	
	int hold = bin.get() - 48;
	
	string send;
	bin >> send;
	
	unsigned int dec_total = 0;
	
	if (bin_digits > 1)
	{
		 dec_total += binToDec(send); //recursive call
	}
	
	if(hold == 1)
	{
		dec_total += pow(2, bin_digits-1);
	}
	
	return dec_total;
}

int main()
{
	while(true)
	{
		cout << "Enter a decimal number:" << endl;
		
		int decimal;
	
		std::cin >> decimal;
		
		stringstream bin_ = decToBin(decimal);
		
		cout << "In binary: " << bin << endl;
	}
	
	while(false)
	{
		cout << "Enter a binary number:" << endl;
		
		string binary;
	
		std::cin >> binary;
		
		cout << "In decimal: " << binToDec(binary) << endl;
	}
}