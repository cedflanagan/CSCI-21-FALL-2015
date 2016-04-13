/*
 * Name        : dl_node.h
 * Author      : Ciaran Flanagan
 * Description : Class declaration for DLNode
 */

#ifndef DL_NODE_H
#define DL_NODE_H

#include <string>

using std::string;

class DLNode
{
    public:
        DLNode();   //default (next_node_ = NULL, previous_node_ = NULL,
                    //contents_ = 0)
        DLNode(string);    //constructor with parameter for contents_
        ~DLNode();
        
        void setContents(string);
        string getContents();
        
        void setNextNode(DLNode*);
        void setPreviousNode(DLNode*);
        
        DLNode* getNextNode();
        DLNode* getPreviousNode();
        
    private:
        DLNode* next_node_;
        DLNode* previous_node_;
        
        string contents_;
};

#endif //DL_NODE_H