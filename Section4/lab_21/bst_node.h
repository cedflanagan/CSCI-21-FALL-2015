/*
 * Name        : bst_node.h
 * Author      : Ciaran Flanagan
 * Description : Class declarations for BSTNode (Binary Search Tree)
 */
 
#ifndef BST_NODE_H
#define BST_NODE_H
 
#include <cstddef>

class BSTNode
{
    
    private:
        BSTNode* left_child_;
        BSTNode* right_child_;
        int contents_;
        
    public:
        /* 
        -right_ and left_child_ set to NULL
        -contents set to 0
        */
        BSTNode();
        
        /*
        -right_ and left_child_ set to NULL
        -contents set by parameter
        */
        BSTNode(int);
        
        /*
        -right_ and left_child_ set to NULL
        */
        ~BSTNode();
        
        /*
        -mutator for contents_
        */
        void set_contents(int);
        
        /*
        -accessors for contents_
        */
        int contents() const;
        int& contents();
        
        /*
        -mutators for right_ and left_child_
        */
        void set_left_child(BSTNode*);
        void set_right_child(BSTNode*);

        /*
        -accessors for left_child_
        */
        BSTNode* left_child() const;
        BSTNode*& left_child();
        
        /*
        -accessors for right_child_
        */
        BSTNode* right_child() const;
        BSTNode*& right_child();
        
};

#endif //BST_NODE_H