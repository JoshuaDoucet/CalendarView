//dateType.h
//A class used to describe a date

#ifndef dateType_H
#define dateType_H 

class dateType
{
public:
	void setDate(int month, int day, int year);
	//Function to set the date.
	//The member variables dMonth, dDay, and dYear are set 
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day;
	//               dYear = year

	void setMonth(int month);
	//Postcondition: dMonth = month

	void setDay(int day);
	//Postcondition: dDay = day

	void setYear(int year);
	//Postcondition: dYear = year

	int getDay() const;
	//Function to return the day.
	//Postcondition: The value of dDay is returned.

	int getMonth() const;
	//Function to return the month.  
	//Postcondition: The value of dMonth is returned.

	int getYear() const;
	//Function to return the year.     
	//Postcondition: The value of dYear is returned.

	void printDate() const;
	//Function to output the date in the form mm-dd-yyyy.
	//Postcondition: Pring date to console

	bool isLeapYear();
	//Function to check if a year is a leap year
	//Postcondition: returns true if year is leap year

	int getNumDaysInMonth(int monthNumber);
	//Postcondition: returns the number of days in a month

	int getJulianDate();
	//Function that finds the julian date using dMonth, dDay, dYear
	//Postcondition: returns the julian date integer of the date object

	int getDaysLeftInYear();
	//Function that finds the num of days left in year
	//Postcondition: returns the number of days left in year

	void addNumDaysToDate(int numDays);
	//Function that add a given number of days to a date.
	//NOTE - this function CANNOT be used to subtract days
	//Example 1-1-2000 plus 32 days is 2-2-2000
	//Postcondition: updates dDay, dMonth, dYear

	dateType(int month = 1, int day = 1, int year = 1900);
	//Constructor to set the date
	//The member variables dMonth, dDay, and dYear are set 
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day; dYear = year;
	//               If no values are specified, the default 
	//               values are used to initialize the member
	//               variables.

private:
	int dMonth; //variable to store the month
	int dDay;   //variable to store the day
	int dYear;  //variable to store the year
};

#endif
