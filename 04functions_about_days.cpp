// Author: Alex Hamptpon


#include <iostream>
#include <string>


/************************************************************************
*								PROTOTYPING								*
*************************************************************************/


void testMenu();
// Postcondition: the test menu is displayed for choice

bool isLeapYear(int year);
// Takes in a value for the year.
// Returns true if given year is a leap yea/ and false otherwise.

int getCenturyValue(int year);
// Precondition: User inputs a value for the year.
// Postcondition: The number for the century (ex. 20 for 2008) 
// is divided by 4 and the remainder is saved as a value.
// value is then subtracted by 3. Finally, value is multiplied by 2.
// The outcome is that any year will give a value of eiher 0, 2, 4, or 6.

int getYearValue(int year);
// Precondition: User inputs a value for the year.
// Postcondition: The last two digits (Ex. 08 of 2008) are extracted.
// That number is then divided by 4 and the remainder is discarded.
// Finally, the number is added to its division by 4.
// Ex. 20008 => 08. 08 divided by 4 = 2. 08 + 2 = 10


int getMonthValue(int month, int year);
// Precondition: User inputs a value for the month and a value for the year.
// Postcondition: values returned are as follows:
// Jan: 0, Feb: 3, Mar: 3, Apr: 6, May: 1, Jun: 4, Jul: 6,
// Aug: 2, Sep: 5, Oct: 0, Nov: 3, Dec: 5. In case of leap year, 
// January is 6 and February is 2. All other months remain the same.

int dayOfWeek(int month, int day, int year);
// Precondition: User inputs the year, month, and day in integer form.
// Postcondition: returns the day of the week in integer form (0 for Sunday, 
// 1 for Monday, etc).

std::string dayOfWeek(int day);
// Precondition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// Postcondition: the name of the day of week is returned as a std::.
// 0 returns SUNDAY, 1 returns MONDAY, and so on.

void validateYear(int& year);
// Postcondition: Ensures the year is after 1582.

void validateMonth(int& month);
// Postcondition: Ensures the month is between 1 and 12, inclusive.

void validateDay(int month, int& day, int year);
// Postcondition: Ensures the day exists for the given month and year.
// Ex: If day is 29 for the month of 02 on a non-leap year, will prompt
// user for a different day.

void validateDay(int& day);
// Postcondition: Ensures day is between 0 and 6, inclusive.
// 0 for Sunday, 1, for Monday . . . 6 for Saturday.



/************************************************************************
*				FUNCTION main()											*
*************************************************************************/

int main()
{
	using namespace std;
	int choice;
	int day, month, year;
	do
	{
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // check if a given year is leap year
			cout << "Please enter a year: ";
			cin >> year;
			validateYear(year);
			if (isLeapYear(year))
				cout << "Year " << year << " is a leap year" << endl;
			else
				cout << "Year " << year << " is NOT a leap year" << endl;
			break;

		case 2: // calculate the century value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			validateYear(year);
			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;

		case 3: // calculate the year value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			validateYear(year);
			cout << "The year value is: " << getYearValue(year) << endl;
			break;

		case 4: // calculate the month value of a given month in a given year
			cout << "Please enter a year and month: ";
			cin >> year >> month;
			validateYear(year);
			validateMonth(month);
			cout << "The month value is: " << getMonthValue(month, year) << endl;
			break;

		case 5: // calculate the day of week of a given date
			cout << "Please enter a year, a month, and a day: ";
			cin >> year >> month >> day;
			validateYear(year);
			validateMonth(month);
			validateDay(month, day, year);
			cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
			break;

		case 6: // print out the name of a given day of week
			cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc.): ";
			cin >> day;
			validateDay(day);
			cout << "The name of the day of the week is: " << dayOfWeek(day) << endl;
			break;

		case 7: 
			cout << "Did you test all functions yet? If not, please rerun the program.\n";
			break;

		default:
			cout << "Wrong option. Please choose from the menu\n";
			break;
		}

		system("pause");
	} while (choice != 7);
}


/************************************************************************
*				FUNCTION testMenu()										*
*************************************************************************/

void testMenu()
{
	using namespace std;
	cout << "\n*************************************\n"
		<< "* Test Menu *\n"
		<< "* 1. isLeapYear *\n"
		<< "* 2. getCenturyValue *\n"
		<< "* 3. getYearValue *\n"
		<< "* 4. getMonthValue *\n"
		<< "* 5. dayOfWeek(month, day, year) *\n"
		<< "* 6. dayOfWeek(day) *\n"
		<< "* 7. Quit *\n"
		<< "*************************************\n\n";
}


/************************************************************************
*				FUNCTION isLeapYear(int year)							*
*************************************************************************/

bool isLeapYear(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}


/************************************************************************
*				FUNCTION getCenturyValue(int year)						*
*************************************************************************/
int getCenturyValue(int year)
{
	int century = year / 100;
	int value = century % 4;
	value = 3 - value;
	value *= 2;
	return value;
}


/************************************************************************
*				FUNCTION getYearValue(int year)							*
*************************************************************************/

int getYearValue(int year)
{
	int value = year % 100;
	int quotient = value / 4;
	return value + quotient;
}


/************************************************************************
*				FUNCTION getMonthValue(int month, int year)				*
*************************************************************************/

int getMonthValue(int month, int year)
{
	using namespace std;
	switch (month)
	{
	case 1:
		if (isLeapYear(year))
			return 6;
		else
			return 0;
		break;

	case 2:
		if (isLeapYear(year))
			return 2;
		else
			return 3;
		break;

	case 3:
	case 11:
		return 3;
		break;

	case 4:
	case 7:
		return 6;
		break;

	case 5:
		return 1;
		break;

	case 6:
		return 4;
		break;

	case 8:
		return 2;
		break;

	case 9:
		return 5;
		break;

	case 10:
		return 0;
		break;

	case 12:
		return 5;
		break;

	default:
		cout << "That is not a valid month. Please try again\n";
		return -1;
	}
}


/************************************************************************
*				FUNCTION dayOfWeek(int month, int day, int year)		*
*************************************************************************/

int dayOfWeek(int month, int day, int year)
{
	int monthValue = getMonthValue(month, year);
	int yearValue = getYearValue(year);
	int centuryValue = getCenturyValue(year);
	int sum = day + monthValue + yearValue + centuryValue;
	int dayOfWeek = sum % 7;
	return dayOfWeek;

}


/************************************************************************
*				FUNCTION dayOfWeek(int day)								*
*************************************************************************/

std::string dayOfWeek(int day)
{
	switch (day)
	{
	case 0:
		return "SUNDAY";
		break;
	case 1:
		return "MONDAY";
		break;
	case 2:
		return "TUESDAY";
		break;
	case 3: 
		return "WEDNESDAY";
		break;
	case 4:
		return "THURSDAY";
		break;
	case 5:
		return "FRIDAY";
		break;
	case 6:
		return "SATURDAY";
		break;
	default:
		return "NONEDAY";
	}
}


/************************************************************************
*				FUNCTION validateYear(int& year)						*
*************************************************************************/

void validateYear(int& year)
{
	using namespace std;
	while (year < 1583)
	{
		cout << "Error: Please enter a year after 1582: ";
		cin >> year;
	}
}


/************************************************************************
*				FUNCTION validateMonth(int& month)						*
*************************************************************************/

void validateMonth(int& month)
{
	using namespace std;
	while (month < 1 || month > 12)
	{
		cout << "Error: Please enter a number for the month between 1 and 12, inclusive: ";
		cin >> month;
	}
}


/************************************************************************
*				FUNCTION validateDay(int month, int& day, int year)		*
*************************************************************************/

void validateDay(int month, int& day, int year)
{
	using namespace std;
	int maximumDay;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maximumDay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maximumDay = 30;
		break;
	case 2:
		if (isLeapYear(year))
			maximumDay = 29;
		else
			maximumDay = 28;
		break;
	}

	while (day < 1 || day > maximumDay)
	{
		cout << "Error: That month has a total of " << maximumDay
			<< " days. Please enter a new day: ";
		cin >> day;
	}
}


/************************************************************************
*				FUNCTION validateDay(int& day)							*
*************************************************************************/

void validateDay(int& day)
{
	using namespace std;
	while (day < 0 || day > 6)
	{
		cout << "Error: Please enter a number between 0 and 6 inclusive.\n"
			<< "Ex. 0 for Sunday, 1 for Monday . . . 6 for Saturday: ";
		cin >> day;
	} 
}







/************************************************************************
*				OUTPUT													*
*************************************************************************/



//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 1
//Please enter a year : 1900
//Year 1900 is NOT a leap year
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 1
//Please enter a year : 2000
//Year 2000 is a leap year
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 2
//Please enter a year : 2008
//The century value is : 6
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 3
//Please enter a year : 2008
//The year value is : 10
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 4
//Please enter a year and month : 2016 10
//The month value is : 0
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 5
//Please enter a year, a month, and a day : 2016 10 12
//The day of the week is : 3
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 6
//Please enter a day of week(0 for Sunday, 1 for Monday, etc.) : 3
//The name of the day of the week is : WEDNESDAY
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 5
//Please enter a year, a month, and a day : 1582 42 32
//Error : Please enter a year after 1582 : 1583
//Error : Please enter a number for the month between 1 and 12, inclusive : 02
//Error : That month has a total of 28 days.Please enter a new day : 29
//Error : That month has a total of 28 days.Please enter a new day : 28
//The day of the week is : 1
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 5
//Please enter a year, a month, and a day : 2000 02 30
//Error : That month has a total of 29 days.Please enter a new day : 29
//The day of the week is : 2
//Press any key to continue . . .
//
//*************************************
//* Test Menu*
//* 1. isLeapYear *
//*2. getCenturyValue *
//*3. getYearValue *
//*4. getMonthValue *
//*5. dayOfWeek(month, day, year) *
//*6. dayOfWeek(day) *
//*7. Quit *
//*************************************
//
//Please choose from menu : 7
//Did you test all functions yet? If not, please rerun the program.
//Press any key to continue . . .







