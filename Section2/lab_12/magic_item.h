/*
 * Name        : magic_item.h
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class definition for MagicItem
 */
 
 #ifndef MAGIC_ITEM_H_
 #define MAGIC_ITEM_H_
 
 #include "item.h"
 
 class MagicItem : public Item
 {
     private:
        //holds description of magic item
        string description_;
        
        //holds amount of mana required to use the magic item
        unsigned int mana_required_;
        
    public:
    
        MagicItem();
        
        MagicItem(string name, unsigned int value, string description, 
        unsigned int mana_required);
            
        virtual ~MagicItem();
        
        void set_description(string description);
        
        void set_mana_required(unsigned int mana_required);
        
        string description();
        
        unsigned int mana_required();
        
        //Format -- name_, $value_, description_, requires mana_required_ mana
        //EXAMPLE -- hat, $10, made of felt, requires 2 mana
        //uses Item::ToString
        string ToString();
 };
 
 #endif //MAGIC_ITEM_H_