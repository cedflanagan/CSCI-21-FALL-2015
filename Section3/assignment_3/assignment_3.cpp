/*
 * Name        : assignment_3.cpp
 * Author      : Ciaran Flanagan
 * Description : Classes definitions for Prize, Box, and Driver
 */
 
#include "assignment_3.h"


Prize::Prize()
    :prizeName("NO NAME"),
     prizeValue(0)
     {}
     
Prize::Prize(string name, unsigned int value)
    :prizeName(name),
     prizeValue(value)
     {}
     
Prize::~Prize()
{}

const bool operator ==(const Prize& prize_one, const Prize& prize_two) 
{
    if(prize_one.getPrizeName() == prize_two.getPrizeName()
    && prize_one.getPrizeValue() == prize_two.getPrizeValue()) 
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void Prize::setPrizeName(string name)
{
    prizeName = name;
}

void Prize::setPrizeValue(unsigned int value)
{
    prizeValue = value;
}

string Prize::getPrizeName() const
{
    return prizeName;
}

unsigned int Prize::getPrizeValue() const
{
    return prizeValue;
}



Box::Box()
    :boxNumber(0),
     boxColor("NO COLOR"),
     prizeCapacity(5),
     prizeCount(0)
     {
         prizes = new Prize[prizeCapacity];
     }

Box::Box(unsigned int number, string color, unsigned int capacity)
    :boxNumber(number),
     boxColor(color),
     prizeCapacity(capacity),
     prizeCount(0)
     {
         prizes = new Prize[prizeCapacity];
     }
     
Box::~Box()
{
    delete [] prizes;
    prizes = NULL;
}

void Box::setBoxNumber(unsigned int number)
{
    boxNumber = number;
}

void Box::setBoxColor(string color)
{
    boxColor = color;
}

unsigned int Box::getBoxNumber()
{
    return boxNumber;
}

string Box::getBoxColor()
{
    return boxColor;
}

unsigned int Box::getPrizeCapacity()
{
    return prizeCapacity;
}

unsigned int Box::getPrizeCount()
{
    return prizeCount;
}

bool Box::addPrize(Prize insert)
{
    for(unsigned int i = 0; i < prizeCapacity; i++)
    {
        if(prizes[i] == scratch)
        {
            prizes[i] = insert;
            
            prizeCount += 1;
            
            return true;
        }
    }
    
    return false;
}

Prize& Box::getPrize(unsigned int index)
{
    if(index > prizeCapacity || prizes[index] == scratch)
    {
        return scratch;
    }
    
    else
    {
        return prizes[index];
    }
}

Prize Box::removePrize(unsigned int index)
{
    if(index > prizeCapacity || prizes[index] == scratch)
    {
        return scratch;
    }
    
    else
    {
        Prize hold = prizes[index];
        
        prizes[index] = scratch;
        
        prizeCount -= 1;
        
        return hold;
    }
}


Driver::Driver()
    :thePrize(Prize()),
     theBox(Box())
     {}
     
Driver::Driver(Prize prize, Box box)
    :thePrize(prize),
     theBox(box)
     {}
     
void Driver::mainMenu()
{
    int select;
    
    cout << "Select from the following by entering a number: " << endl;
    cout << "1. Prize Menu" << endl;
    cout << "2. Box Menu" << endl;
    
    cin >> select;
    
    if(select == 1)
    {
        prizeMenu();
    }
    
    else if(select == 2)
    {
        boxMenu();
    }
    
    else
    {
        cout << "Invalid Selection. Terminating." << endl;
    }
}

void Driver::prizeMenu()
{
    int select;
    
    cout << "Select from the following by entering a number: " << endl;
    cout << "1. setPrizeName" << endl;
    cout << "2. setPrizeValue" << endl;
    cout << "3. getPrizeName" << endl;
    cout << "4. getPrizeValue" << endl;
    
    cin >> select;
    
    switch(select)
    {
        case 1:
            thePrize.setPrizeName("PRIZE NAME");
            break;
        case 2:
            thePrize.setPrizeValue(123);
            break;
        case 3:
            cout << "The prize is named \"" << thePrize.getPrizeName() << "\"" << endl;
            break;
        case 4:
            cout << "The prize has a value of \"" << thePrize.getPrizeValue() << "\"" << endl;
            break;
        default:
            cout << "Invalid Selection. Terminating." << endl;
            break;
    }
}

void Driver::boxMenu()
{
    int select;
    
    cout << "Select from the following by entering a number: " << endl;
    cout << "1. setBoxNumber" << endl;
    cout << "2. setBoxColor" << endl;
    cout << "3. getBoxNumber" << endl;
    cout << "4. getBoxColor" << endl;
    cout << "5. getPrizeCapacity" << endl;
    cout << "6. getPrizeCount" << endl;
    cout << "7. addPrize" << endl;
    cout << "8. getPrize" << endl;
    cout << "9. removePrize" << endl;
    
    cin >> select;
    
    switch(select)
    {
        case 1:
            theBox.setBoxNumber(123);
            break;
        case 2:
            theBox.setBoxColor("A COLOR");
            break;
        case 3:
            cout << "The box is number \"" << theBox.getBoxNumber() << "\"" << endl;
            break;
        case 4:
            cout << "The box has a color of \"" << theBox.getBoxColor() << "\"" << endl;
            break;
        case 5:
            cout << "The box has a capacity of \"" << theBox.getPrizeCapacity() << "\" prizes" << endl;
            break;
        case 6:
            cout << "The box contains \"" << theBox.getPrizeCount() << "\" prizes" << endl;
            break;
        case 7:
            {
                Prize nPrize("New Prize", 123);
                theBox.addPrize(nPrize);
                break;
            }
        case 8:
            cout << "The first prize in the box is named \"" << theBox.getPrize(1).getPrizeName() << "\"" << endl;
            break;
        case 9:
            cout << "The prize named \"" << theBox.removePrize(1).getPrizeName() << "\" has been removed" << endl;
            break;
        default:
            cout << "Invalid Selection. Terminating." << endl;
            break;
    }
}

/*
int main()
{
    Driver main_driver_;
    
    while(true)
    {
        main_driver_.mainMenu();    
    }
    
    return 0;
}
*/