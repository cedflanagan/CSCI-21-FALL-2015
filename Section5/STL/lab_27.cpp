/*
 * Name        : lab_27.cpp
 * Author      : Ciaran Flanagan
 * Description : Using the STL
 */

#include "lab_27.h"

// CLASS (and regular) FUNCTION DEFINITIONS GO HERE

/*
* Add an item to the end of the chest.
* @param Item& item_to_add - The item to be added to the end of the chest
*/
void TreasureChest::AddItem(const Item& item_to_add)
{
    chest_.push_back(item_to_add);
}

/*
* Insert an item at the specified zero-indexed position in the chest. If
* position is not valid for the chest, add the item to the end of the chest.
* Note this function inserts, not replaces.
* @param Item& item_to_add - The item to be inserted into the chest
* @param u-int position    - The zero-indexed position where the insertion is
*                            to take place.
*/
void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position)
{
    if(position <= chest_.size())
    {
        chest_.insert(chest_.begin() + position, item_to_add);
    }
    
    else
    {
        chest_.push_back(item_to_add);
    }
}

/*
* Get a pointer to an item at a specified zero-indexed position in the chest.
* @param u-int position - The zero-indexed position of the item
* @return const Item* - A pointer to the item if position is valid, else NULL
*/
const Item* TreasureChest::GetItem(unsigned int position)
{
    if(position >= chest_.size())
    {
        return NULL;
    }
    
    Item* hold_ = &chest_.at(position);
    
    return hold_;
}

/*
* Remove an item from the chest at a specified zero-indexed position.
* @param u-int position - The zero-indexed position of the item
* @return Item          - A copy of the Item removed from the chest
* @throw string("ERROR: Remove at invalid position") if position is not valid
*/
Item TreasureChest::RemoveItem(unsigned int position)
{
    Item hold_;
    
    if(position >= chest_.size())
    {
        throw string("ERROR: Remove at invalid position");     
    }
    
    else
    {
        hold_ = chest_.at(position);
        chest_.erase(chest_.begin() + position);
    }
    
    return hold_;
}

/*
* Clear the chest of all items.
*/
void TreasureChest::Clear()
{
    chest_.clear();
}

/*
* Check to see if the chest is empty.
* @return bool - True if the chest is empty, else false
*/
bool TreasureChest::Empty() const
{
    return chest_.empty();
}

/*
* Get the size/number of items currently in the chest.
* @return u-int - The current size of the chest
*/
unsigned int TreasureChest::GetSize() const
{
    return chest_.size();
}

/*
* Sort the items in the chest by name, using the sort function
* from the C++ standard algorithm library.
*/
void TreasureChest::SortByName()
{
    sort(chest_.begin(), chest_.end(), CompareItemsByName);
}

/*
* Sort the items in the chest by value, using the sort function
* from the C++ standard algorithm library.
*/
void TreasureChest::SortByValue()
{
    sort(chest_.begin(), chest_.end(), CompareItemsByValue);
}

/*
* Sort the items in the chest by quantity, using the sort function
* from the C++ standard algorithm library.
*/
void TreasureChest::SortByQuantity()
{
    sort(chest_.begin(), chest_.end(), CompareItemsByQuantity);
}

/*
* Place the names of the items in the chest on the specified stream,
* formatted as ITEM_NAME, ITEM_NAME, ..., ITEM_NAME
* Places "Chest Empty!" on the stream if the chest is empty
*/
ostream& operator<<(ostream& outs, const TreasureChest& src)
{
    if(src.chest_.empty())
    {
        outs << "Chest Empty!";
    }
    
    else
    {
        for(unsigned int i = 0; i < src.chest_.size() - 1; i++)
        {
            outs << src.chest_.at(i).name_ << ", ";
        }
        
        outs << src.chest_.back().name_;
    }
    
    return outs;
}

/*
* Returns a string representation of what the overloaded << operator would
* output. Remember: 'this' is a keyword that points to the current object
* @uses Overloaded << Operator
* @return string - A string in the format ITEM_NAME, ... or "Chest Empty!"
*/
string TreasureChest::ToString()
{
    stringstream ss;
    
    if(chest_.empty())
    {
        ss << "Chest Empty!";
    }
    
    else
    {
        
        for(unsigned int i = 0; i < chest_.size() - 1; i++)
        {
            ss << chest_.at(i).name_ << ", ";
        }
        
        ss << chest_.back().name_;
    }
    
    return ss.str();
}

/*
 * Compare two items by name.
 * @return true if lsrc.name_ < rsrc.name_, else false
 */
bool CompareItemsByName(const Item& lsrc, const Item& rsrc)
{
    return (lsrc.name_ < rsrc.name_);
}

/*
 * Compare two items by value.
 * @return true if lsrc.value_ < rsrc.value_, else false
 */
bool CompareItemsByValue(const Item& lsrc, const Item& rsrc)
{
    return (lsrc.value_ < rsrc.value_);
}

/*
 * Compare two items by quantity.
 * @return true if lsrc.quantity_ < rsrc.quantity_, else false
 */
bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc)
{
    return (lsrc.quantity_ < rsrc.quantity_);
}
