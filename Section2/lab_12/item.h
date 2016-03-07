/*
 * Name        : item.h
 * Author      : Ciaran Flanagan
 * Date        : 3/2/2016
 * Description : Class definition for Item
 */
 
 #ifndef ITEM_H_
 #define ITEM_H_
 
 #include <string>
 #include <sstream>
 #include <iomanip>
 
 using std::string;
 using std::stringstream;
 
 class Item
 {
     private:
        //name of item
        string name_;
        
        //value of item
        unsigned int value_;
     
     public:
     
     Item();
     
     Item(string name, unsigned int);
     
     virtual ~Item();\
     
     void set_name(string name);
     
     void set_value(unsigned int value);
     
     string name();
     
     unsigned int value();
     
     
     //Returns a string containing name_ and value_
     //Format -- name_, $value_
     //Example -- shoes, $25
     string ToString();
 };
 
 #endif //PERSON_H_