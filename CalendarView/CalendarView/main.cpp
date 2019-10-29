//main.cpp
//This file is used to test the several class types used for the Calendar Program
//Class types used - dateType, dateTypeExt, dayType, calendarType
//dateTypeExt is a derived class that inherits the dateType members. dateTypeExt "is a" dateType
//calendarType is a class that "has a" dayType class object and "has a" dateTypeExt class, 
//which "is a" dateType object 

#include <iostream>
#include <string>
#include <iomanip>
#include "calendarType.h"
using namespace std;

//Displays a user-specified calander month
void printCalander();

//Functions used to debug the Calander application
void debugApp();
void debugDateType();
void debugDateTypeExt();
void debugDayType();


int main() {
	//Variable that stores a user's selection from the menu
	int menuChoice;

	//Main program loop
	do {
		//Display main menu
		cout << "\nSelect an option.\n"
			<< "1: Print a calander month.\n"
			<< "2: Debug Application.\n"
			<< "3. Quit.\n";
		//Get user selection
		cin >> menuChoice;

		//Main menu switch
		switch (menuChoice) {
		case 1:
			printCalander();
			break;
		case 2:
			debugApp();
			break;
		case 3:
			break;
		default:
			cout << "\n--Invalid Selection--.\n";
		}
	} while (menuChoice != 3);

	return 0;
}

//Displays a user-specified calander month
void printCalander() {
	int month, year;
	calendarType* date;

	//Prompt user for a date
	cout << "Display a calander month.\n";

	do {
		cout << "Enter a Month and Year: MM YYYY: ";
		cin >> month >> year;
		if (year < 1500)
			cout << "\nCalanders before January 1500 cannot be displayed.\n";
	} while (year < 1500);

	//Set date
	date = new calendarType(month, year);

	//Display calander
	(*date).printCalendar();
	delete date;
}

//Test application
void debugApp() {
	debugDateType();
	debugDateTypeExt();
	debugDayType();
}

//Test dateTypeExt class
void debugDateTypeExt() {
	cout << "\nDEBUG dateTypeExt\n-----------------\n";
	extDateType date = extDateType(1, 31, 1994);
	cout << "\nPrint the months of the year.\n";
	for (int i = 0; i < 12; i++){
		date.setMonth(i+1);
		cout << date.getMonthNameString() << " ";
	}

	cout << "\nPrint month and year of date: ";
	date.printMonthAndYear();
	cout << endl;
}

//Test dayType class
void debugDayType() {
	cout << "\nDEBUG dateType\n-----------------\n";
	dayType day = dayType();
	cout << "\nPrint day of week: " << day.getDayName();
	cout << "\n Print all abreviations for days of the week.\n";
	day.printAbrevDays();
	cout << endl;
}

////Test dateType class
void debugDateType() {
	cout << "\nDEBUG dateType\n-----------------\n";
	dateType sampleDate = dateType(3, 31, 2033);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nSet new date of 4-7-1501";
	sampleDate.setDate(4, 7, 1501);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nSet day to 28.";
	sampleDate.setDay(28);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nSet day to 41.";
	sampleDate.setDay(41);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nSet year to 3104. ";
	sampleDate.setYear(3104);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nNumber of days in February 3104 " << sampleDate.getNumDaysInMonth(2);

	cout << "\nAdd 3 days to date.";
	sampleDate.addNumDaysToDate(3);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;

	cout << "\nAdd 71,401 days to date.";
	sampleDate.addNumDaysToDate(71401);
	cout << "\nDate: ";
	sampleDate.printDate();
	cout << endl;
}
