// * Interface for Separate Compilation Project
// * Money class holds various values of money
// * Used in application to take in formatted
// * text from file and set as Money object.
// *
// * Author: Alex Hampton
// */

#ifndef ALEXHAMPTONMONEY_H
#define ALEXHAMPTONMONEY_H

#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <cctype>
using namespace std;


// Class for amount of money in U.S. currency.
class Money
{
public:
	/****************************************
	*		friend functions				*
	*****************************************/

	friend Money operator +(const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initialized with values.
	// Returns the sum of the values of amount1 and amount2.

	friend Money operator -(const Money& amount1, const Money& amount2);
	// PreconditioN: amount1 and amount2 have been initialized with values;
	// Returns the difference of amount1 and amount2.

	friend Money operator -(const Money& amount);
	// Precondition: amount has been given a value.
	// Returns the negative of the value of amount.

	friend bool operator ==(const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initializes with values.
	// Returns true if amount1 and amount2 have the same value.
	// Returns false otherwise.

	friend bool operator <(const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initializes with values.
	// Returns true is amount1 is less than amount2
	// Returns false otherwise.

	friend bool operator <=(const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initializes with values.
	// Returns true if amount1 is less than or equal to amount2.
	// Returns false otherwise.

	friend bool operator > (const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initializes with values.
	// Returns true if amount1 is greater than amount2.
	// Returns false otherwise.

	friend bool operator >=(const Money& amount1, const Money& amount2);
	// Precondition: amount1 and amount2 have been initializes with values.
	// Returns true if amount1 is greater than or equal to amount2.
	// Returns false otherwise.

	friend istream& operator >>(istream& ins, Money& amount);
	// Overloads the >> operator so it can be used to input values of type Money.
	// Notation for inputting negative amounts is as in -$100.00.
	// Precondition: If ins is a file input stream, then ins has already been
	// connected to a file.

	friend ostream& operator <<(ostream& outs, const Money& amount);
	// Overloads the << operator so it can be used to output values of type Money.
	// Precedes each output value of type Money with a dollar sign.
	// Precondition: If outs is a file output stream, then outs 
	// has already been connected to a file.



	/****************************************
	*		member functions				*
	*****************************************/
	Money(long dollars, int cents);
	// Initializes the object so its value represents an amount with the
	// dollars and cents given by the arguments. If the amount is negative,
	// then both dollars and cents must be negative.

	Money(long dollars);
	// Initializes the object so its value repreesnts $dollars.00.

	Money(double amount);
	// Initializes the object so its value represents $amount.

	Money();
	//Initializes the object so its value represents $0.00.

	double getValue() const;
	// Precondition: The calling object has been given a value.
	// Returns the amount of money recorded in the data of the calling object.

	Money percent(int percentFigure) const;
	// Returns a percentage of the money amount in the
	// calling object. For example, if percentFigure is 10,
	// then the value returned is 10% of the amount of
	// money represented by the calling object.

private:
	long allCents;
};


#endif // ALEXHAMPTONMONEY_H
