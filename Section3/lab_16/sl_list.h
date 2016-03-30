/*
 * Name        : sl_list.h
 * Author      : Ciaran Flanagan / April Browne
 * Description : Class definition for SLList
 */
 
#ifndef SL_LIST_H
#define SL_LIST_H

#include <string>
#include <sstream>

#include "sl_node.h"

using std::string;
using std::stringstream;


class SLList
{
    
    public:
        //sets head_ to NULL
        //sets size_ to 0
        SLList();
        ~SLList();
        
        //Creates a new dynamic SLNode with the contents of the parameter and 
        //attaches as the new head of the list.
        void InsertHead(int);
        //Removes the head node from the list, or does nothing if the list is 
        //empty.
        void RemoveHead();
        //Clears the entire contents of the list, freeing all memory associated 
        //with all nodes.
        void Clear();
        
        unsigned int size() const;
        
        //Returns a string representation of the contents of all nodes in the 
        //list, in the format NUM1, NUM2, ..., LASTNUM returns the empty string 
        //on an empty list (i.e. returns "")
        string ToString() const;
        
    
    private:
        SLNode* head_;
        unsigned int size_;
};

#endif //SL_LIST_H