/*
 * Name        : bs_tree.cpp
 * Author      : Ciaran Flanagan
 * Description : Functions for Binary Search Tree
 */

#include "bs_tree.h"

/*
Creates a new BSTNode, inserts it into the tree, and returns true.
If the integer is already in the tree, does not insert, and returns 
false.
*/
bool BSTree::Insert(int contents, BSTNode*& root)
{
    if(size_ == 0)
    {
        BSTNode* temp_ = new BSTNode(contents);
        root_ = temp_;
        
        size_ += 1;
        
        return true;
    }
    
    else if(contents < root->contents())
    {
        if(root->left_child() == NULL)
        {
            BSTNode* temp_ = new BSTNode(contents);
            
            root->set_left_child(temp_);
            
            size_ += 1;
            
            return true;
        }
        
        else
        {
            return Insert(contents, root->left_child());
        }
    }
    
    
    else if(contents > root->contents())
    {
        if(root->right_child() == NULL)
        {
            BSTNode* temp_ = new BSTNode(contents);
            
            root->set_right_child(temp_);
            
            size_ += 1;
            
            return true;
        }
        
        else
        {
            return Insert(contents, root->right_child());
        }
    }
    
    return false;
    
}

/*
clears the entire contents of the tree, freeing all memory 
associated with all nodes.
*/
void BSTree::Clear(BSTNode*& root)
{
    if(size_ == 0)
    {
        return;
    }
    
    if(root->left_child() != NULL)
    {
        Clear(root->left_child());
    }
    
    if(root->right_child() != NULL)
    {
        Clear(root->right_child());
    }
    
    size_ -= 1;
    
    delete root;
}

/*
creates a string of the data in all nodes in the tree, in ascending 
order, separate by spaces (there should be a space after the last 
output value)
*/
string BSTree::InOrder(BSTNode* root)
{
    if (size_ == 0)
    {
        return "";
    }
    
    stringstream output;
    
    if(root->left_child() != NULL)
    {
        output << InOrder(root->left_child());
    }
    
    output << root->contents();
    output << " ";
    
    if(root->right_child() != NULL)
    {
        output << InOrder(root->right_child());
    }
    
    return output.str();
}

/*
traverses the tree and removes the node containing the target integer
if present and returns true.
return false if the target integer is not in the tree (or the tree is
empty)
*/
bool BSTree::Remove(int target, BSTNode*& root)
{
    if(size_ == 0)
    {
        return false;
    }
    
    else if(root->contents() > target && root->left_child() != NULL)
    {
        return Remove(target, root->left_child());
    }
    
    else if(root->contents() < target && root->right_child() != NULL)
    {
        return Remove(target, root->right_child());
    }
    
    else if(root->contents() == target)
    {
        //root has no children
        if(root->left_child() == NULL && root->right_child() == NULL)
        {
            delete root;
            
            root = NULL;
            
            size_ -= 1;
            
            return true;
        }
        
        //root has two children
        else if(root->right_child() != NULL && root->left_child() != NULL)
        {
            int min = FindMin(root->right_child());
            
            root->set_contents(min);
            
            return Remove(min, root->right_child()); 
        }
        
        //root has only a left child
        else if(root->left_child() != NULL && root->right_child() == NULL)
        {
            BSTNode* temp = root;
            
            root = root->left_child();
            
            delete temp;
            
            size_ -= 1;
            
            return true;
        }
        
        //root has only a right child
        else if(root->left_child() == NULL && root->right_child() != NULL)
        {
             BSTNode* temp = root;
            
            root = root->right_child();
            
            delete temp;
            
            size_ -= 1;
            
            return true;
        }
        
        
    }
    
    
    return false;
}

/*
returns the valuse of the smallest node in the tree.
helper function for private Remove()
*/
int BSTree::FindMin(BSTNode* root) const
{
    if(root->left_child() != NULL)
    {
        return FindMin(root->left_child());
    }
    
    return root->contents();
}

/*
-set root_ to NULL
-set size_ to 0
*/
BSTree::BSTree()
    :root_(NULL),
     size_(0){}

//calls Clear
BSTree::~BSTree()
{
    Clear(root_);
}

//calls private function Insert
bool BSTree::Insert(int contents)
{
    return Insert(contents, root_);
}

//calls private function Remove(int, root)
bool BSTree::Remove(int target)
{
    return Remove(target, root_);
}

//if tree is empty return 0, otherwise calls private function FindMin(root)
int BSTree::FindMin()
{
    if(size_ == 0)
    {
        return 0;
    }
    
    return FindMin(root_);
}

//calls private function Clear
void BSTree::Clear()
{
    Clear(root_);
}

//accessor for size_
unsigned int BSTree::size()
{
    return size_;
}

//calls private function InOrder
string BSTree::InOrder()
{
    return InOrder(root_);
}