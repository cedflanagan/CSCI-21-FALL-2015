/*
 * Name        : money.cpp
 * Author      : Ciaran Flanagan
 * Description : Class functions for Money
 */
 
#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = std::abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// REST OF CLASS FUNCTION DEFINITIONS GO HERE

const Money operator -(const Money& amount1, const Money& amount2)
{
    // Get all the cents of object 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all the cents of object 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    
    //calculate difference of cents
    int diff_all_cents = all_cents1 - all_cents2;
    
    // Handle the fact that money can be negative
    int abs_all_cents = abs(diff_all_cents);
    int final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    
    // If the result of the operation was negative, negate final dollars and cents
    if (diff_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
    }
    
    return Money(final_dollars, final_cents);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    bool equivalent;
    
    // Get all the cents of object 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all the cents of object 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    
    if ( all_cents1 == all_cents2)
    {
        equivalent = true;
    }
    
    else
    {
        equivalent = false;
    }
    
    return equivalent;
}

const Money operator -(const Money &amount)
{
    // Get all the cents of object 1
    int all_cents = amount.cents_ + amount.dollars_ * 100;
    
    int negative_cents = 0 - all_cents;
    
    int final_dollars = negative_cents / 100;
    int final_cents = negative_cents % 100;
    
    
    return Money(final_dollars, final_cents);
}

ostream& operator <<(ostream &out, const Money &amount)
{
    if(amount.cents_ >= 0 && amount.dollars_ >= 0)
    {
        out << '$';
    }
    
    else
    {
        out << "$-";
    }
    
    out << abs(amount.dollars_) << '.';
    out << std::setfill('0') << std::setw(2) << abs(amount.cents_);
    
    return out;
}