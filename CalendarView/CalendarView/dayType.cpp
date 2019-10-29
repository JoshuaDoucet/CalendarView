//dayType.cpp
//Implementation file for dayType.h

#include "dayType.h"

//Default Constructor, Initialize dayOfWeek to Sunday
dayType::dayType() { dayOfWeek = 1; }

//Constructor given a day of the week
dayType::dayType(int day) { dayOfWeek = day; }

//Postcondition: return dayOfWeek integer, 1 to 7
int dayType::getDayOfWeek() { return dayOfWeek; }

//Postcondition: dayOfWeek = day if a valid day of the week is provided
void dayType::setDayOfWeek(int day) {
	if (day > 0 || day < 8)
		dayOfWeek = day;
	else
		cout << "\nValid days are 1 through 7.";
}

//Postcondition: prints a list of week abreviations to console application with width 7
void dayType::printAbrevDays() {
	cout << endl;
	for (int day = 0; day < 7; day++)
		cout << left << setw(7) << abreviatedDays[day];
}

//Poscondition: return the name of a day of the week. Example Sunday, or Monday
string dayType::getDayName() { return nameOfDays[dayOfWeek - 1]; }

//Postcondition: return an abreviation of a day of the week. Example Sun, or Mon
string dayType::getDayAbrev() { return abreviatedDays[dayOfWeek - 1]; }