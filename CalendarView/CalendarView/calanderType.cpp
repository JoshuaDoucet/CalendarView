//calendarType.cpp
//This is the implementation file for calendarType.h

#include "calendarType.h"

//Postcondition: return the day of week that the month starts on for the given year
dayType calendarType::firstDayOfMonth() {
	//Variable used as a starting point to determine day of week that other months start on
	extDateType initialDate = extDateType(1, 1, 1500);
	//The initialDate variable starts on initialDay of the week
	dayType initialDay(2); //Monday
	//Day of week to be returned
	dayType firstDayOfMonth; 
	//Counts num days between initialDate and the dDateExt of the calendarType object
	int daysBetweenDates = 0;
	//Distance of the dDateExt from the initialDate regarding days of week
	//Example if initialDate is a Monday and dDateExt is a Thursday, weekDisplacment is 3
	int weekDisplacement;

	//While the initial month and year do not match the targeted month and year
	while (initialDate.getYear() != dDateExt.getYear()
		|| initialDate.getMonth() != dDateExt.getMonth()) {
		//Add the number of days in initial month to daysBetween days
		daysBetweenDates += initialDate.getNumDaysInMonth(initialDate.getMonth());
		//Update initial date to the following month
		if (initialDate.getMonth() + 1 > 12) {
			initialDate.setMonth(1);
			initialDate.setYear(initialDate.getYear() + 1);
		}
		else {
			initialDate.setMonth(initialDate.getMonth() + 1);
		}
		//Continue adding days in month to counter until the dates match
	}

	//Modulo 7 because there are 7 days in week. daysBetweenDates % 7 gives the days of week displacment
	weekDisplacement = daysBetweenDates % 7;

	//Update the first day of the month that the dDateExt starts on.
	if(initialDay.getDayOfWeek() + weekDisplacement > 7)
		//Ex: if initDay is Monday(2) and displacment is 6 the start of week is Sunday(1) of the first day of week
		firstDayOfMonth.setDayOfWeek(initialDay.getDayOfWeek() + weekDisplacement - 7);
	else
		firstDayOfMonth.setDayOfWeek(initialDay.getDayOfWeek() + weekDisplacement);

	return firstDayOfMonth;
}

//Postcondition: dDateExt.dMonth = month
void calendarType::setMonth(int month) {
	dDateExt.setMonth(month);
}

//Postcondition: dDateExt.dYear = year
void calendarType::setYear(int year) {
	dDateExt.setYear(year);
}

//Postcondition: return dDateExt.dMonth
int calendarType::getMonth() {
	return dDateExt.getMonth();
}

//Postcondition: return dDateExt.dYear
int calendarType::getYear() {
	return dDateExt.getYear();
}

//Postcondtion: prints a calendar for the month stored in dDateExt to the app console
void calendarType::printCalendar() {
	cout << endl;
	dDateExt.printMonthAndYear();
	dDayOfWeek.printAbrevDays();

	int dayCounter = 1;
	cout << endl;
	for (int row = 1; row < 7; row++) {
		for (int col = 1; col < 8; col++) {
			if (row == 1 && col >= dDayOfWeek.getDayOfWeek()) {
				cout << setw(7) << left << dayCounter;
				dayCounter++;
			}
			else if (row == 1)
				cout << setw(7) << left << " ";
			else if (dayCounter <= dDateExt.getNumDaysInMonth(dDateExt.getMonth())) {
				cout << setw(7) << left << dayCounter;
				dayCounter++;
			}
		}
		cout << endl;
	}
}

//Default constructor
calendarType::calendarType() {
	dDateExt = extDateType();
	dDayOfWeek = firstDayOfMonth();
}

//Constructor to build extDateType and dayType object using a month day and year
calendarType::calendarType(int month, int year) {
	dDateExt = extDateType(month, 1, year); //Day is set to one, calendarType is not concerned with day
	dDayOfWeek = firstDayOfMonth();
}

//Constructor given extDateType and dayType objects
calendarType::calendarType(extDateType date, dayType day) {
	dDateExt = date;
	dDayOfWeek = day;
}