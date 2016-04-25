/*
 * Name        : bst_node.cpp
 * Author      : Ciaran Flanagan
 * Description : Functions for BSTNode (Binary Search Tree)
 */

#include "bst_node.h"


/* 
-right_ and left_child_ set to NULL
-contents set to 0
*/
BSTNode::BSTNode()
    :left_child_(NULL),
     right_child_(NULL),
     contents_(0){}

/*
-right_ and left_child_ set to NULL
-contents set by parameter
*/
BSTNode::BSTNode(int contents)
    :left_child_(NULL),
     right_child_(NULL),
     contents_(contents){}

/*
-right_ and left_child_ set to NULL
*/
BSTNode::~BSTNode()
{
    right_child_ = NULL;
    left_child_ = NULL;
}

/*
-mutator for contents_
*/
void BSTNode::set_contents(int contents)
{
    contents_ = contents;
}

/*
-accessors for contents_
*/
int BSTNode::contents() const
{
    return contents_;
}

int& BSTNode::contents()
{
    return contents_;
}

/*
-mutators for right_ and left_child_
*/
void BSTNode::set_left_child(BSTNode* left_child)
{
    left_child_ = left_child;
}

void BSTNode::set_right_child(BSTNode* right_child)
{
    right_child_ = right_child;
}

/*
-accessors for left_child_
*/
BSTNode* BSTNode::left_child() const
{
    return left_child_;
}

BSTNode*& BSTNode::left_child()
{
    return left_child_;
}

/*
-accessors for right_child_
*/
BSTNode* BSTNode::right_child() const
{
    return right_child_;
}

BSTNode*& BSTNode::right_child()
{
    return right_child_;
}