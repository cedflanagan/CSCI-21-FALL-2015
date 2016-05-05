/*
 * Name        : bs_tree.h
 * Author      : Ciaran Flanagan
 * Description : Class definition for Binary Search Tree
 */
 
#ifndef BS_TREE_H
#define BS_TREE_H
 
#include "bst_node.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class BSTree
{
    private:
        /*
        Creates a new BSTNode, inserts it into the tree, and returns true.
        If the integer is already in the tree, does not insert, and returns 
        false.
        */
        bool Insert(int, BSTNode*&);
        
        /*
        clears the entire contents of the tree, freeing all memory 
        associated with all nodes.
        */
        void Clear(BSTNode*&);
        
        /*
        creates a string of the data in all nodes in the tree, in ascending 
        order, separate by spaces (there should be a space after the last 
        output value)
        */
        string InOrder(BSTNode*);
        
        /*
        traverses the tree and removes the node containing the target integer
        if present and returns true.
        return false if the target integer is not in the tree (or the tree is
        empty)
        */
        bool Remove(int, BSTNode*&);
        
        /*
        returns the valuse of the smallest node in the tree.
        helper function for private Remove()
        */
        int FindMin(BSTNode*) const;
        
        //points to the root node of the search tree
        BSTNode* root_;
        
        //holds the numebr of nodes in the tree
        unsigned int size_;
        
    public:
        /*
        -set root_ to NULL
        -set size_ to 0
        */
        BSTree();
        
        //calls Clear
        ~BSTree();
        
        //calls private function Insert
        bool Insert(int);
        
        //calls private function Remove(int, root)
        bool Remove(int);
        
        //if tree is empty return 0, otherwise calls private function FindMin(root)
        int FindMin();
        
        //calls private function Clear
        void Clear();
        
        //accessor for size_
        unsigned int size();
        
        //calls private function InOrder
        string InOrder();
        
    
};

#endif //BS_TREE_H