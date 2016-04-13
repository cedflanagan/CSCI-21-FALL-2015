/*
 * Name        : dl_list.h
 * Author      : Ciaran Flanagan / April Browne
 * Description : Class declaration for DLList
 */
 
#ifndef DL_LIST_H
#define DL_LIST_H

#include <string>
#include <iostream>

#include "dl_node.h"

using std::string;
using std::ostream;
using std::cout;
using std::endl;


class DLList
{
    
    public:
        //sets head_ and tail_ to NULL
        //sets size_ to 0
        DLList();
        ~DLList();
        
        unsigned int getSize() const;
        
        //create new DLNode with newContents and attach at head_
        void pushFront(string);
        //create new DLNode with newContents and attach at tail_
        void pushBack(string);
        
        //Creates a new SLNode with the contents of the parameter and inserts it
        //into the correct position in the list. (lower values closer to head)
        void insert(string);
        
        //Returns the contents of the head node. Returns 0 if the list is empty.
        string getFront() const;
        //Returns the contents of the head node. Returns 0 if the list is empty.
        string getBack() const;
        
        //return true if target is in list, else return false.
        bool get(string) const;
        
        //remove current head node. Do nothing if empty.
        void popFront();
        //remove current tail node. Do nothing if empty.
        void popBack();
        
        //Remove the first occurrence of the supplied parameter found as the
        //data of a node. Return true on successful removal or false if the list
        //is empty or the value is not found.
        bool removeFirst(string);
        
        //Remove all occurrences of the supplied parameter found as the
        //data of a node. Return true on successful removal or false if the list
        //is empty or the value is not found.
        bool removeAll(string);
        
        //Traverse (parameter) nodes, delete the ending node, and set head_ and
        //tail_ to the following and preceding node respectively. 
        //Returns the deleted node.
        DLNode* pullChair(int);
        
        //Clears the entire contents of the list, freeing all memory associated 
        //with all nodes.
        void clear();
        
        //display the contents of each node in the list to the output stream.
        friend ostream& operator<<(ostream&, const DLList&);
        
    
    private:
        DLNode* head_;
        DLNode* tail_;
        unsigned int size_;
        

};

#endif //DL_LIST_H