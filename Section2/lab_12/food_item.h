/*
 * Name        : food_item.h
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class definition for FoodItem
 */
 
 #ifndef FOOD_ITEM_H_
 #define FOOD_ITEM_H_
 
 #include "item.h"
 
 class FoodItem : public Item
 {
     private:
        //calorie amount for item
        unsigned int calories_;
        
        //holds unit of measure
        string unit_of_measure_;
        
        //holds a count of units
        double units_;
        
    public:
        
        FoodItem();
    
        FoodItem(string name, unsigned int value, unsigned int calories,
        string unit_of_measure, double units);
            
        virtual ~FoodItem();
        
        void set_calories(unsigned int calories);
        
        void set_unit_of_measure(string unit_of_measure);
        
        void set_units(double units);
        
        unsigned int calories();
        
        string unit_of_measure();
        
        double units();
        
        //Format -- name_, $value_, units_ unit_of_measure_, calories_ calories
        //EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
        //uses Item::ToString
        //units_ formatted to exactly two decimal places
        string ToString();
 };
 
 #endif //FOOD_ITEM_H_