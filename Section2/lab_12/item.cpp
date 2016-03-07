/*
 * Name        : item.cpp
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class functions for Item
 */
 
 #include "item.h"
 
Item::Item()
        :   name_("item"),
            value_(0){}
 
Item::Item(string name = "item", unsigned int value = 0)
        :   name_(name),
            value_(value){}
            
Item::~Item()
{}
            

void Item::set_name(string name)
{
    name_ = name;
}

void Item::set_value(unsigned int value)
{
    value_ = value;
}
     
string Item::name()
{
    return name_;
}
     
unsigned int Item::value()
{
    return value_;
}

//Returns a string containing name_ and value_
//Format -- name_, $value_
//Example -- shoes, $25
string Item::ToString()
{
    stringstream ss;
    
    ss << name_ << ", $" << value_;
    
    return ss.str();
}