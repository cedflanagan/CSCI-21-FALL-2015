/*
 * Name        : box.h
 * Author      : Ciaran Flanagan
 * Description : Template class Box
 */

#include <string>
#include <iostream>
using std::string;
using std::ostream;
 
template<typename T> 
class Box
{
    public:
        //Constructor
        Box(T new_contents)
            : contents(new_contents)
            {};
            
        T getContents()
        {
            return contents;  
        };
        
        void setContents(T new_contents)
        {
            contents = new_contents;    
        };
        
        //Overloaded stream operator for Box
        friend ostream& operator <<(ostream &out, Box the_box)
        {
            out << the_box.contents;
            
            return out;
        };
        
            
    private:
        T contents;
 };
 
 /*
 * Function Name: Sum
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */
 template<typename T>
 T Sum(T values[], unsigned int size)
 {
     T sum = T();
     
     for(int i = 0; i < size; i++)
     {
         sum += values[i];
     }
     
     return sum;
 }
 
