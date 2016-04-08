/*
 * Name        : musical_chairs.cpp
 * Author      : Ciaran Flanagan
 * Description : Class declaration for MusicalChairs
 */

#include "dl_list.h"

#include <fstream>

using std::ifstream;

void populateList(DLList& roster, string file, int* numbers)
{
    ifstream ifs.open(file);
    
    sstream is; //catch integers from file
    int isc = 0;//count
    
    while(true)
    {
        if(ifstream::eof(ifs.peek()))
        {
            break;
        }
         
        else if(isalpha(ifs.peek())
        {
            roster.pushBack(ifs.getline());
        }
         
        else
        {
            is << ifs.getline();
            isc ++;
        }
    }
    
    numbers = new int[isc];
    
    for(int i = 0; i < isc; i++)
    {
        is >> numbers[i];
    }
    
    ifs.close();
}

void playGame(DLList& roster, int* numbers)
{
    cout << "All players, in order:" << endl;
    cout << roster << endl;
    
    int length = roster.getSize();
    
    for(int i = 0; i < length - 1; i++)
    {
        roster.rem
    }
    
}

int MusicalChairs(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Execuatable must be followed by a single file path." << endl;
        cout << "Exiting." << endl;
        
        return 0;
    }
    
    DLList roster_;
    
    string* names_;
    int* numbers_;
    
    populateList(roster_, argv[1], names_, numbers_);
    
    
    
    
    
    
}