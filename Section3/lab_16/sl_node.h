/*
 * Name        : sl_node.h
 * Author      : Ciaran Flanagan
 * Description : Class definition for SLNode
 */

#ifndef SL_NODE_H
#define SL_NODE_H

#include <cstddef>

class SLNode
{
    public:
        SLNode(); //default (next_node_ = NULL, contents_ = 0)
        SLNode(int); //constructor with parameter for contents_
        ~SLNode();
        
        void set_contents(int);
        int contents();
        
        void set_next_node(SLNode*);
        SLNode* next_node();
        
    private:
        SLNode* next_node_;
        
        int contents_;
};

#endif //SL_NODE_H