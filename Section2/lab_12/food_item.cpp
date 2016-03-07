/*
 * Name        : food_item.cpp
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class functions for FoodItem
 */
 
 #include "food_item.h"
 
FoodItem::FoodItem()
        :   Item("fooditem", 0),
            calories_(0),
            unit_of_measure_("nounits"),
            units_(0){}
 
FoodItem::FoodItem(string name = "fooditem", unsigned int value = 0,
    unsigned int calories = 0, string unit_of_measure = "nounits",
            double units = 0)
        :   Item(name, value),
            calories_(calories),
            unit_of_measure_(unit_of_measure),
            units_(units){}
            
FoodItem::~FoodItem()
{}
            

void FoodItem::set_calories(unsigned int calories)
{
    calories_ = calories;
}

void FoodItem::set_unit_of_measure(string unit_of_measure)
{
    unit_of_measure_ = unit_of_measure;
}
        
void FoodItem::set_units(double units)
{
    units_ = units;
}
        
unsigned int FoodItem::calories()
{
    return calories_;
}
        
string FoodItem::unit_of_measure()
{
    return unit_of_measure_;
}
        
double FoodItem::units()
{
    return units_;
}
        
//Format -- name_, $value_, units_ unit_of_measure_, calories_ calories
//EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
//uses Item::ToString
//units_ formatted to exactly two decimal places
string FoodItem::ToString()
{
    stringstream ss;
    
    ss << std::fixed << std::setprecision(2);
    ss << Item::ToString() << ", " << units_ << " " << unit_of_measure_ 
        << ", " << calories_ << " calories";
    
    return ss.str();
}
