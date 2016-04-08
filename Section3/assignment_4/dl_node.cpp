/*
 * Name        : dl_node.cpp
 * Author      : Ciaran Flanagan
 * Description : Function definitions for DLNode
 */
 
#include "dl_node.h" 

DLNode::DLNode()
    :next_node_(NULL),
     previous_node_(NULL),
     contents_("Empty")
     {}

DLNode::DLNode(string contents)
    :next_node_(NULL),
     previous_node_(NULL),
     contents_(contents)
     {}
     
DLNode::~DLNode()
{}

void DLNode::setContents(string contents)
{
    contents_ = contents;
}

string DLNode::getContents()
{
    return contents_;
}
        
void DLNode::setNextNode(DLNode* next_node)
{
    next_node_ = next_node;
}

DLNode* DLNode::getNextNode()
{
    return next_node_;
}

void DLNode::setPreviousNode(DLNode* next_node)
{
    previous_node_ = previous_node_;
}

DLNode* DLNode::getPreviousNode()
{
    return previous_node_;
}