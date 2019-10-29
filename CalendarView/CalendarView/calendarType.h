//calendarType.h
//A class used to describe a calendar month. This class uses a extDateType and dayType object

#ifndef calenderType_H
#define calenderType_H
#include "extDateType.h"
#include "dayType.h"

class calendarType {
public:
	//Postcondition: return the day of week that the month starts on for the given year
	dayType firstDayOfMonth();

	//Postcondition: dDateExt.dMonth = month
	void setMonth(int month);

	//Postcondition: dDateExt.dYear = year
	void setYear(int year);

	//Postcondition: return dDateExt.dMonth
	int getMonth();

	//Postcondition: return dDateExt.dYear
	int getYear();

	//Postcondtion: prints a calander for the month stored in dDateExt to the app console
	void printCalendar();

	//Default constructor
	calendarType();

	//Constructor to build extDateType and dayType object using a month day and year
	calendarType(int month, int year);

	//Constructor given extDateType and dayType objects
	calendarType(extDateType date, dayType day);

private:
	extDateType dDateExt;
	dayType dDayOfWeek;
};

#endif // !calanderType_H

