/*
 * Name        : dl_list.cpp
 * Author      : Ciaran Flanagan
 * Description : Class definition for DLList
 */
 
#include "dl_list.h"
#include "dl_node.h"

DLList::DLList()
    :head_(NULL),
     tail_(NULL),
     size_(0)
     {}
     
DLList::~DLList()
{
    clear();
}

void DLList::pushFront(string contents)
{
    DLNode* temp_ = new DLNode(contents);
    
    temp_->setNextNode(head_);
    head_->setPreviousNode(tail_);
    
    head_ = temp_;
    
    if(tail_ == NULL)
    {
        tail_ = head_;
    }
    
    size_ += 1;
}

void DLList::pushBack(string contents)
{
    DLNode* temp_ = new DLNode(contents);
    
    if(tail_ != NULL)
    {
        tail_->setNextNode(temp_);
        temp_->setPreviousNode(tail_);
    }
    
    tail_ = temp_;
    
    if(head_ == NULL)
    {
        head_ = tail_;
    }
    
    size_ += 1;
}

unsigned int DLList::getSize() const
{
    return size_;
}

void DLList::insert(string contents)
{
    DLNode* temp_ = new DLNode(contents);
    
    if(size_ == 0)
    {
        temp_->setNextNode(head_);
        head_ = temp_;
        tail_ = temp_;
        
        size_ += 1;
    }
    
    else if(head_->getContents() >= temp_->getContents())
    {
        temp_->setNextNode(head_);
        head_->setPreviousNode(temp_);
        head_ = temp_;
    
        if(temp_->getNextNode() == NULL)
        {
            tail_ = temp_;
        }
        
        size_ += 1;
    }
    
    else
    {
        DLNode* iterator_ = head_;
        
        while(iterator_->getNextNode() != NULL
        && iterator_->getNextNode()->getContents() < temp_->getContents())
        {
            iterator_ = iterator_->getNextNode();
        }
            
        temp_->setNextNode(iterator_->getNextNode());
        temp_->setPreviousNode(iterator_);
        temp_->getNextNode()->setPreviousNode(temp_);
        
        iterator_->setNextNode(temp_);
        
        if(temp_->getNextNode() == NULL)
        {
            tail_ = temp_;
        }
        
        size_ += 1;
    }
}

string DLList::getFront() const
{
    if (head_ == NULL)
    {
        return 0;
    }
    
    return head_->getContents();
}

string DLList::getBack() const
{
    if (tail_ == NULL)
    {
        return 0;
    }
    
    return tail_->getContents();
}

bool DLList::get(string search) const
{
    if(size_ == 0)
    {
        return false;
    }
    
    else
    {
        DLNode* iterator_ = head_;
        
        while(iterator_ != NULL)
        {
            if(iterator_->getContents() == search)
            {
                return true;
            }
            
            iterator_ = iterator_->getNextNode();
        }
        
        return false;
    }
}

void DLList::popFront()
{
    if(head_ == NULL)
    {
        return;
    }
    
    else
    {
        DLNode* temp_ = head_;
        head_ = head_->getNextNode();
        delete temp_;
        
        size_ -= 1;
    }
    
    if(size_ == 0)
    {
        head_ = NULL;
        tail_ = NULL;
    }
    
}

void DLList::popBack()
{
    if(tail_ == NULL)
    {
        return;
    }
    
    else
    {
        DLNode* temp_ = tail_;
        tail_ = tail_->getPreviousNode();
        delete temp_;
        
        size_ -= 1;
    }
    
    if(size_ == 0)
    {
        head_ = NULL;
        tail_ = NULL;
    }
    
}

bool DLList::removeFirst(string search)
{
    
    if(size_ == 0)
    {
        return false;
    }
    
    else
    {
        DLNode* iterator_ = head_;
        
        while(iterator_ != NULL)
        {
            if(iterator_->getContents() == search)
            {
                iterator_->getPreviousNode()->setNextNode(iterator_->getNextNode());
                iterator_->getNextNode()->setPreviousNode(iterator_->getPreviousNode());
                
                delete iterator_;
                
                size_ -= 1;
                
                return true;
            }
            
            iterator_ = iterator_->getNextNode();
        }
        
        return false;
    }
}

bool DLList::removeAll(string search)
{
    bool success = false;
    
    if(size_ == 0)
    {
        return false;
    }
    
    else
    {
        DLNode* iterator_ = head_;
        
        while(iterator_ != NULL)
        {
            if(iterator_->getContents() == search)
            {
                iterator_->getPreviousNode()->setNextNode(iterator_->getNextNode());
                iterator_->getNextNode()->setPreviousNode(iterator_->getPreviousNode());
                
                delete iterator_;
                
                size_ -= 1;
                
                success = true;
            }
            
            iterator_ = iterator_->getNextNode();
        }
        
        return success;
    }
}

bool DLList::removeChair(int position)
{
    if(position > size || size == 0)
    {
        return false;
    }
    
    else
    {
        DLNode* iterator_ = head_;
        
        for(int i = 1; i <= position; i++)
        {
            iterator_ = iterator_->getNextNode();
        }
    
        iterator_->getPreviousNode()->setNextNode(iterator_->getNextNode());
        iterator_->getNextNode()->setPreviousNode(iterator_->getPreviousNode());
                
        delete iterator_;
                
        size_ -= 1;
                
        success = true;
    }
}

void DLList::clear()
{
    while (size_ != 0)
    {
        popFront();
    }
}

ostream& operator<<(ostream& os, const DLList& src)
{
    if(src.head_ == NULL)
    {
        os << "";
        
        return os;
    }
    
    DLNode* temp_ = src.head_;

    for(unsigned int i = 1; i < src.size_; i++)
    {
        os << temp_->getContents() << ", ";
        
        temp_ = temp_->getNextNode();
    }
    
    os << temp_->getContents();
    
    return os;
}




