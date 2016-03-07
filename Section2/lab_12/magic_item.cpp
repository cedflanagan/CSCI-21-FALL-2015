/*
 * Name        : magic_item.cpp
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class functions for MagicItem
 */
 
 #include "magic_item.h"
 
MagicItem::MagicItem()
        :   Item("magicitem", 0),
            description_("no description"),
            mana_required_(0){}
 
MagicItem::MagicItem(string name = "magicitem", unsigned int value = 0,
            string description = "no description",
            unsigned int mana_required = 0)
        :   Item(name, value),
            description_(description),
            mana_required_(mana_required){}
            
MagicItem::~MagicItem()
{}
            

void MagicItem::set_description(string description)
{
    description_ = description;
}
        
void MagicItem::set_mana_required(unsigned int mana_required)
{
    mana_required_ = mana_required;
}
        
string MagicItem::description()
{
    return description_;
}
        
unsigned int MagicItem::mana_required()
{
    return mana_required_;
}
        
//Format -- name_, $value_, description_, requires mana_required_ mana
//EXAMPLE -- hat, $10, made of felt, requires 2 mana
//uses Item::ToString
string MagicItem::ToString()
{
    stringstream ss;
    
    ss << Item::ToString() << ", " << description_ << ", requires " 
        << mana_required_ << " mana";
    
    return ss.str();
}
