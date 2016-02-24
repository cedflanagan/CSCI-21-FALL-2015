/*
 * Name        : lab_7.cpp
 * Author      : Ciaran Flanagan / April Browne
 * Description : Working with File I/O
 */
#include "lab_7.h"

// CODE HERE -- FUNCTION DEFINITION FOR ProcessFile()

/*
 * Open and read the contents of a text file. 
 * Read each line and perform functions according to content:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */
bool ProcessFile(string filename)
{
    ifstream file_in;
    file_in.open(filename.c_str());
    
    string line;
    
    while(getline(file_in, line))
    {
        if (line == "10")
        {
            OnTen();
        }
        
        else if (line == "20")
        {
            OnTwenty();
        }
        
        else if (line == "30")
        {
            OnThirty();
        }
        
        else if (line == "40")
        {
            OnForty();
        }
        
        else if (line == "50")
        {
            OnFifty();
        }
        
        else
        {
            OnError();
        }
    }
    
    bool success = file_in.is_open();
    
    file_in.close();
    
    if (file_in.is_open())
    {
        success = false;
    }
    
    return success;
}

void ProcessArguments(int argc, char* argv[])
{
    
    
    for (int i = 1; i < argc; i++)
    {
        string compare = argv[i];
        
        if (compare == "10")
        {
            OnTen();
        }
        
        else if (compare == "20")
        {
            OnTwenty();
        }
        
        else if (compare == "30")
        {
            OnThirty();
        }
        
        else if (compare == "40")
        {
            OnForty();
        }
        
        else if (compare == "50")
        {
            OnFifty();
        }
        
        else
        {
            OnError();
        }
    }
}