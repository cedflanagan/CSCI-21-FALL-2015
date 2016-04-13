/*
 * Name        : musical_chairs.cpp
 * Author      : Ciaran Flanagan
 * Description : Class declaration for MusicalChairs
 */

#include "dl_list.h"

#include <fstream>

using std::ifstream;

void populateList(DLList* play_list, ifstream& file)
{
    int num_players_;
    
    file >> num_players_;
    
    for(int i = 0; i < num_players_; i++)
    {
        string player_;
        file >> player_;
        
        play_list->pushBack(player_);
    }
}

void musicalChairs(DLList* play_list, ifstream& file)
{
    cout << "Starting list of players:" << endl << play_list << endl << endl;
    
    while(play_list->getSize() > 1)
    {
        int steps_;
        
        file >> steps_;
        
        cout << "Player " << steps_ << ", " << play_list->pullChair(steps_) <<
            "has been eliminated." << endl;
            
        cout << "Remaining players:" << endl << play_list << endl << endl;
    }
    
    cout << "The winner is: " << play_list->getFront() << endl << endl;
}


int main(int argc, char *argv[])
{
    if(argc < 1)
    {
        cout << "Argument (filename) must be included with executable." << endl;
        
        return 0;
    }
    
    ifstream file_(argv[1]);
    
    DLList* play_list_ = new DLList();
    
    populateList(play_list_, file_);
    
    musicalChairs(play_list_, file_);
    
    return 1;
}