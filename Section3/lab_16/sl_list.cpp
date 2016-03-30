/*
 * Name        : sl_list.cpp
 * Author      : Ciaran Flanagan
 * Description : Class definition for SLList
 */
 
#include "sl_list.h"
#include "sl_node.h"

SLList::SLList()
    :head_(NULL),
     size_(0)
     {}
     
SLList::~SLList()
{
    Clear();
    return;
}

void SLList::InsertHead(int contents)
{
    SLNode* temp_ = new SLNode(contents);
    temp_->set_next_node(head_);
    head_ = temp_;
    
    size_ += 1;
}

void SLList::RemoveHead()
{
    if(head_ == NULL)
    {
        return;
    }
    
    SLNode* temp_ = head_;
    head_ = head_->next_node();
    delete temp_;
    
    size_ -= 1;
}

void SLList::Clear()
{
    while (size_ != 0)
    {
        RemoveHead();
    }
}

unsigned int SLList::size() const
{
    return size_;
}

string SLList::ToString() const
{
    if(head_ == NULL)
    {
        return "";
    }
    
    SLNode* temp_ = head_;
    stringstream ss;
    
    for(unsigned int i = 1; i < size_; i++)
    {
        ss << temp_->contents() << ", ";\
        
        temp_ = temp_->next_node();
    }
    
    ss << temp_->contents();
    
    return ss.str();
}
