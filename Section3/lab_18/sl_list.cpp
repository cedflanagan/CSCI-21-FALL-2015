/*
 * Name        : sl_list.cpp
 * Author      : Ciaran Flanagan
 * Description : Class definition for SLList
 */
 
#include "sl_list.h"
#include "sl_node.h"

SLList::SLList()
    :head_(NULL),
     tail_(NULL),
     size_(0)
     {}
     
SLList::~SLList()
{
    Clear();
}


void SLList::Insert(int contents)
{
    SLNode* temp_ = new SLNode(contents);
    
    if(size_ == 0)
    {
        temp_->set_next_node(head_);
        head_ = temp_;
        tail_ = temp_;
        
        size_ += 1;
    }
    
    else if(head_->contents() >= temp_->contents())
    {
        temp_->set_next_node(head_);
        head_ = temp_;
    
        if(temp_->next_node() == NULL)
        {
            tail_ = temp_;
        }
        
        size_ += 1;
    }
    
    else
    {
        SLNode* iterator_ = head_;
        
        while(iterator_->next_node() != NULL
        && iterator_->next_node()->contents() < temp_->contents())
        {
            iterator_ = iterator_->next_node();
        }
            
        temp_->set_next_node(iterator_->next_node());
        iterator_->set_next_node(temp_);
        
        if(temp_->next_node() == NULL)
        {
            tail_ = temp_;
        }
        
        size_ += 1;
    }
}

bool SLList::RemoveFirstOccurence(int search)
{
    
    bool success;
    
    if(size_ == 0)
    {
        return false;
    }
    
    else if(head_->contents() == search)
    {
        SLNode* temp_ = head_;
        head_ = head_->next_node();
        delete temp_;
        
        size_ -= 1;
        
        if(head_ == NULL || head_->next_node() == NULL)
        {
            tail_ = head_;
        }
        
        return true;
    }
    
    else
    {
        SLNode* iterator_ = head_;
        
        while(iterator_->next_node() != NULL 
        && iterator_->next_node()->contents() != search)
        {
            iterator_ = iterator_->next_node();
        }
        
        if(iterator_->next_node() == NULL)
        {
            return false;
        }
        
        else
        {
            SLNode* temp_ = iterator_->next_node();
            iterator_->set_next_node(temp_->next_node());
            delete temp_;
            
            size_ -= 1;
            
            if(iterator_->next_node() == NULL)
            {
                tail_ = iterator_;
            }
            
            return true;
        }
    }
    
    
    
    return success;
}

void SLList::Clear()
{
    while (size_ != 0)
    {
        RemoveHead();
    }
}

int SLList::GetHead() const
{
    if (head_ == NULL)
    {
        return 0;
    }
    
    return head_->contents();
}

int SLList::GetTail() const
{
    if (tail_ == NULL)
    {
        return 0;
    }
    
    return tail_->contents();
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


void SLList::InsertHead(int contents)
{
    SLNode* temp_ = new SLNode(contents);
    temp_->set_next_node(head_);
    head_ = temp_;
    
    if(tail_ == NULL)
    {
        tail_ = head_;
    }
    
    size_ += 1;
}

void SLList::InsertTail(int contents)
{
    SLNode* temp_ = new SLNode(contents);
    
    if(tail_ != NULL)
    {
        tail_->set_next_node(temp_);
    }
    
    tail_ = temp_;
    
    if(head_ == NULL)
    {
        head_ = tail_;
    }
    
    size_ += 1;
}

void SLList::RemoveHead()
{
    if(head_ == NULL)
    {
        return;
    }
    
    else
    {
        SLNode* temp_ = head_;
        head_ = head_->next_node();
        delete temp_;
    }
    
    size_ -= 1;
        
    
    if(size_ == 0)
    {
        head_ = NULL;
        tail_ = NULL;
    }
    
}

void SLList::RemoveTail()
{
    if(tail_ == NULL)
    {
        return;
    }
    
    else if(head_ == tail_)
    {
        delete head_;
    }
    
    else
    {
        SLNode* iterator_ = head_;
    
        while(iterator_->next_node() != tail_)
        {
            iterator_ = iterator_->next_node();
        }
        
        delete tail_;
        
        tail_ = iterator_;
    }
    
    size_ -= 1;
    
    
    if(size_ == 0)
    {
        head_ = NULL;
        tail_ = NULL;
    }
    
}