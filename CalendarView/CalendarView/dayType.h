//dayType.h
//This class is used to describe a day of the week. Ex Tuesday

#ifndef dayType_H
#define dayType_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dayType {
public:
	//Postcondition: return dayOfWeek integer, 1 to 7
	int getDayOfWeek();

	//Postcondition: dayOfWeek = day if a valid day of the week is provided
	void setDayOfWeek(int day);

	//Poscondition: return the name of a day of the week. Example Sunday, or Monday
	string getDayName();

	//Postcondition: return an abreviation of a day of the week. Example Sun, or Mon
	string getDayAbrev();

	//Postcondition: prints a list of week abreviations to console application.
	void printAbrevDays();

	//Default Constructor, Initialize dayOfWeek to Sunday
	dayType();

	//Constructor given a day of the week
	dayType(int day);

private:
	int dayOfWeek; //The day of week from 1 to 7. Sunday is 1, Saturday is 7
	string nameOfDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday" };
	string abreviatedDays[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
};
#endif // !dayType_H

