//extDateType.cpp
//This is the implementation file for extDateType.h

#include "extDateType.h"
#include <string>

extDateType::extDateType(): dateType() {
	monthString = getMonthNameString();
}

extDateType::extDateType(int month = 1, int day = 1, int year = 1900) :dateType(month, day, year) {
	monthString = getMonthNameString();
}

string extDateType::getMonthNameString() {
	string monthNames[] = {"January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December"};
	return monthNames[getMonth() -1]; // -1 keep array in bounds 0 to 11
}

void extDateType::printMonthAndYear() {
	cout << getMonthNameString() << " " << getYear();
}