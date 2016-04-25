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
    temp_->setPreviousNode(tail_);
    
    head_->setPreviousNode(temp_);
    tail_->setNextNode(temp_);
    
    head_ = temp_;
    
    size_ += 1;
    
    if(tail_ == NULL)
    {
        tail_ = head_;
    }
}

void DLList::pushBack(string contents)
{
    DLNode* temp_ = new DLNode(contents);
    
    temp_->setNextNode(head_);
    temp_->setPreviousNode(tail_);
    
    tail_->setNextNode(temp_);
    head_->setPreviousNode(temp_);
    
    tail_ = temp_;
    
    size_ += 1;
    
    if(head_ == NULL)
    {
        head_ = tail_;
    }
    
}

unsigned int DLList::getSize() const
{
    return size_;
}

void DLList::insert(string contents)
{
    DLNode* temp_ = new DLNode(contents);
    
    if(size_ == 0 || head_->getContents() >= temp_->getContents())
    {
        pushFront(contents);
    }
    
    else
    {
        DLNode* iterator_ = head_->getNextNode();
        
        while(iterator_->getNextNode() != NULL
        &&iterator_->getNextNode() != head_
        && iterator_->getNextNode()->getContents() < temp_->getContents())
        {
            iterator_ = iterator_->getNextNode();
        }
        
        if(iterator_ == tail_)
        {
            pushBack(contents);
        }
        
        else
        {
            temp_->setNextNode(iterator_->getNextNode());
            temp_->getNextNode()->setPreviousNode(temp_);
            
            temp_->setPreviousNode(iterator_);
            iterator_->setNextNode(temp_);
            
            size_ += 1;
        }
    }
}

string DLList::getFront() const
{
    if (head_ == NULL)
    {
        return "EMPTY";
    }
    
    return head_->getContents();
}

string DLList::getBack() const
{
    if (tail_ == NULL)
    {
        return "EMPTY";
    }
    
    return tail_->getContents();
}

bool DLList::get(string search) const
{
    if(size_ == 0)
    {
        return false;
    }
    
    if(head_->getContents() == search)
    {
        return true;
    }
    
    DLNode* iterator_ = head_->getNextNode();
    
    while(iterator_ != NULL
    &&iterator_ != head_)
    {
        if(iterator_->getContents() == search)
        {
            return true;
        }
        
        iterator_ = iterator_->getNextNode();
    }
    
    return false;
    
}

void DLList::popFront()
{
    if(size_ == 0)
    {
        return;
    }
    
    else
    {
        DLNode* temp_ = head_;
        
        head_ = head_->getNextNode();
        head_->setPreviousNode(tail_);
        tail_->setNextNode(head_);
        
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
    if(size_ == 0)
    {
        return;
    }
    
    else
    {
        DLNode* temp_ = tail_;
        
        tail_ = tail_->getPreviousNode();
        tail_->setNextNode(head_);
        head_->setPreviousNode(tail_);
        
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
    
    if(head_->getContents() == search)
    {
        popFront();
        
        return true;
    }
    
    DLNode* iterator_ = head_->getNextNode();
        
    while(iterator_ != NULL
    &&iterator_ != head_)
    {
        if(iterator_->getContents() == search)
        {
            if(iterator_ == tail_)
            {
                popBack();
            }
            
            else
            {
            iterator_->getPreviousNode()->setNextNode(iterator_->getNextNode());
            iterator_->getNextNode()->setPreviousNode(iterator_->getPreviousNode());
            
            delete iterator_;
            
            size_ -= 1;
            }
            
            return true;
        }
        
        iterator_ = iterator_->getNextNode();
    }
    
    return false;
}

bool DLList::removeAll(string search)
{
    bool success = false;
    
    if(size_ == 0)
    {
        return false;
    }
    
    while(head_->getContents() == search)
    {
        popFront();
        
        success = true;
    }
    
    DLNode* iterator_ = head_->getNextNode();
    
    while(iterator_ != NULL
    &&iterator_ != head_)
    {
        if(iterator_->getContents() == search)
        {
            if(iterator_ == tail_)
            {
                popBack();
            }
            
        else
            {
            iterator_->getPreviousNode()->setNextNode(iterator_->getNextNode());
            iterator_->getNextNode()->setPreviousNode(iterator_->getPreviousNode());
            
            delete iterator_;
            
            size_ -= 1;
            }
            
            success = true;
        }
        
        iterator_ = iterator_->getNextNode();
    }
    
    
    return success;
}

DLNode* DLList::pullChair(int steps)
{
    if(size_ == 0)
    {
        DLNode* scratch_ = new DLNode();
        return scratch_;
    }
    
    DLNode* temp_ = head_;
    for(int i = 0; i < steps; i++)
    {
        temp_ = temp_->getNextNode();
    }
    
    head_ = temp_->getNextNode();
    tail_ = temp_->getPreviousNode();
    
    DLNode* send_ = temp_;
    
    delete temp_;
    
    size_ -= 1;
    
    if(size_ > 1)
    {
        head_->setPreviousNode(tail_);
        tail_->setNextNode(head_);
    }
    
    return send_;
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
    if(src.size_ == 0)
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




