//dateType.cpp
//Implementation file for dateType.h

#include <iostream>
#include "dateType.h"

using namespace std;

int dateType::getDay() const { return dDay; }

int dateType::getMonth() const { return dMonth; }

int dateType::getYear() const { return dYear; }

void dateType::printDate() const {
	cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeapYear() {
	/*Checks for a leap year. If year is evenly divisible by 4 with no remainder and the year
	divided by 100 has a remainder then it is a leap year OR if the year divided by 400 has a remainder
	of 0 then it is a leap year*/
	if (dYear % 4 == 0 && dYear % 100 != 0 || dYear % 400 == 0)
		return true;
	else
		return false;
}

void dateType::setDate(int month, int day, int year) {
	/*All integer values for year will be considered valid.
	Negative dates should refer to dates prior to 0 AD*/
	dYear = year;

	if (month > 0 && month < 13)
		dMonth = month;
	else
		dMonth = 1; //A value of 1 will indicate an invalid month has been entered

	if (day > 0 && day <= dateType::getNumDaysInMonth(dMonth))
		dDay = day;
	else
		dDay = 1; //A value of 1 will indicate an invalid day has been entered

}

void dateType::setMonth(int month) { 
	if (month > 0 && month < 13)
		dMonth = month;
	else
		dMonth = 1; //A value of 1 will indicate an invalid month has been entered
}

void dateType::setDay(int day) {
	if (day > 0 && day <= dateType::getNumDaysInMonth(dMonth))
		dDay = day;
	else
		dDay = 1; //A value of 1 will indicate an invalid day has been entered}
}

void dateType::setYear(int year) { 
	dYear = year;
}

int dateType::getNumDaysInMonth(int monthNumber) {
	int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//Check for leap year. If February and leap year, add 1 to days in month
	if (monthNumber == 2 && dateType::isLeapYear())
		return (daysInMonths[monthNumber - 1] + 1);
	else
		return daysInMonths[monthNumber - 1];
}

int dateType::getJulianDate() {
	int julianCounter = 0;
	for (int i = 1; i <= dMonth; i++) {
		if (i == dMonth) //if counter is = to month only add the day value of the date
			julianCounter += dDay;
		else //else add the number of days in month to the julian counter
			julianCounter += getNumDaysInMonth(i);
	}
	return julianCounter;
}

int dateType::getDaysLeftInYear() {
	if (dateType::isLeapYear())
		return 366 - getJulianDate();
	else
		return 365 - getJulianDate();
}

void dateType::addNumDaysToDate(int numDays) {
	//newDate is a messy variable with multiple uses throughout this function.
	//It is used to calculate a new date
	int newDate = getJulianDate() + std::abs(numDays);
	//Determine the number of years that pass after adding numDays
	while (newDate > 365){
		if (isLeapYear() && newDate > 366) {
			newDate -= 366;
			dYear++;
		}
		else {
			newDate -= 365;
			dYear++;
		}
	}

	//newDdate now represents the julian date in a calander year
	//Determine what month and dat of month the julian date represents
	for (int month = 1; month <= 12; month++) {
		if (newDate - getNumDaysInMonth(month) > 0)
			//newDate is larger than the numDaysInMonth
			//Subtract numDays in month from newDate
			newDate -= getNumDaysInMonth(month);
		else { //else newDate is a number < the numDaysInMonth
			//Thus...
			dMonth = month;
			dDay = newDate;
			break; //Exit loop early, or risk unwanted calculations
		}
	}
}

//Constructor with parameters
dateType::dateType(int month, int day, int year) {
	dateType::setDate(month, day, year);
}


