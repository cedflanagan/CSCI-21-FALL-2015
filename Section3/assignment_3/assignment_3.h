/*
 * Name        : assignment_3.h
 * Author      : Ciaran Flanagan
 * Description : Classes declarations for Prize, Box, and Driver
 */

#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::cin;
using std::endl;

class Prize
{
    public:
        //set itemName to "NO NAME", itemValue to "0"
        Prize();    
        Prize(string, unsigned int);
        ~Prize();
        
        friend const bool operator ==(const Prize&, const Prize&);
        
        void setPrizeName(string);
        void setPrizeValue(unsigned int);
        string getPrizeName() const;
        unsigned int getPrizeValue() const;
    
    private:
        string prizeName;
        unsigned int prizeValue;
        
};


class Box
{
    public:
        //set boxNumber to "0", boxColor to "NO COLOR", prizeCapacity to "5",
        //prizeCount to "0", initialize prizes to match prizeCapacity
        Box();
        Box(unsigned int, string, unsigned int);
        ~Box();
        
        void setBoxNumber(unsigned int);
        void setBoxColor(string);
        
        unsigned int getBoxNumber();
        string getBoxColor();
        unsigned int getPrizeCapacity();
        unsigned int getPrizeCount();
        
        bool addPrize(Prize);
        Prize& getPrize(unsigned int);
        Prize removePrize(unsigned int);
        
    private:
        unsigned int boxNumber;
        string boxColor;
        Prize scratch;
        Prize* prizes;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
};


class Driver
{
    public:
        Driver();
        Driver(Prize, Box);
        
        void mainMenu();
        
        void prizeMenu();
        
        void boxMenu();
        
    private:
        Prize thePrize;
        Box theBox;
  
    
};