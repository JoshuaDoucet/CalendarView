//extDateType.h
//This class extends the functionality of dayType by adding a string representation of the month 

#ifndef extDateType_H
#define extDateType_H
#include "dateType.h"
#include <iostream>
using namespace std;

class extDateType : public dateType {
public:
	//Default constructor
	extDateType();

	//Constructor given three values, month, day, year
	extDateType(int, int, int);

	//Postcondition: month and year printed to console
	//Example: March 2017
	void printMonthAndYear();

	//Postcondition: returns a string representing a month name based on dMonth
	string getMonthNameString();

private:
	string monthString; //variable to store month name in string format
};

#endif // !extDateType_H

