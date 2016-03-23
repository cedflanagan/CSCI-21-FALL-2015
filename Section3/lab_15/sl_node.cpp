/*
 * Name        : sl_node.cpp
 * Author      : Ciaran Flanagan
 * Description : Function definitions for SLNode
 */
 
#include "sl_node.h" 

SLNode::SLNode()
    :next_node_(NULL),
     contents_(0)
     {}

SLNode::SLNode(int contents)
    :next_node_(NULL),
     contents_(contents)
     {}
     
SLNode::~SLNode()
{
    return;
}

void SLNode::set_contents(int contents)
{
    contents_ = contents;
}

int SLNode::contents()
{
    return contents_;
}
        
void SLNode::set_next_node(SLNode* next_node)
{
    next_node_ = next_node;
}

SLNode* SLNode::next_node()
{
    return next_node_;
}