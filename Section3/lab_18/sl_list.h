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
        
        //Clears the entire contents of the list, freeing all memory associated 
        //with all nodes.
        void Clear();
        
        //Creates a new SLNode with the contents of the parameter and inserts it
        //into the correct position in the list. (lower values closer to head)
        void Insert(int);
        //Remove the first occurrence of the supplied parameter found as the
        //data of a node. Return true on successful removal or false if the list
        //is empty or the value is not found.
        bool RemoveFirstOccurence(int);
        
        //Returns the contents of the head node. Returns 0 if the list is empty.
        int GetHead() const;
        //Returns the contents of the head node. Returns 0 if the list is empty.
        int GetTail() const;
        
        unsigned int size() const;
        
        //Returns a string representation of the contents of all nodes in the 
        //list, in the format NUM1, NUM2, ..., LASTNUM returns the empty string 
        //on an empty list (i.e. returns "")
        string ToString() const;
        
    
    private:
        //Creates a new dynamic SLNode with the contents of the parameter and 
        //attaches as the new head of the list.
        void InsertHead(int);
        //Creates a new dynamic SLNode with the contents of the parameter and 
        //attaches as the last node (tail) of the list.
        void InsertTail(int);
        
        //Removes the head node from the list, or does nothing if the list is 
        //empty.
        void RemoveHead();
        //Removes the last node (tail) from the list, or does nothing if the
        //list is empty.
        void RemoveTail();
        
        SLNode* head_;
        SLNode* tail_;
        unsigned int size_;
        

};

#endif //SL_LIST_H