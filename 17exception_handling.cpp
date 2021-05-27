// Demonstrates the use of Exception Handling, Exception classes, 
// and throwing exceptions within a separate function.
// Program takes in a 24-hour time from the user and formats 
// it to common time. Ex. 23:46 becomes 11:46 PM.

// Author: Alex Hampton
// 04/13/2021

#include <iostream>
#include <string>
using namespace std;

class TimeFormatMistake
{};
// Used to throw exception for below formatTime(string input)

string formatTime(string input) throw (TimeFormatMistake);
// Takes in a string
// Postcondition: Throws TimeFormatMistake exception if not in
// '0:00' or '00:00' format. Also throws exception if hour is
// not between 0 and 23, or minute is not between 0 and 59.
// Returns a string in common time format. Ex. "15:52" becomes "3:52 PM"


int main()
{
	char goAgain = 'y';
	while (goAgain == 'y' || goAgain == 'Y')		// loop if user chooses to
	{
		string input;
		cout << "Enter time in 24-hour notation:\n";
		cin >> input;
		try
		{
			string formatted = formatTime(input);	// format string, throw exception in function
			cout << "That is the same as\n";
			cout << formatted << endl;				// output formatted string

			cout << "Again?(y/n)\n";
			cin >> goAgain;
		}
		catch (TimeFormatMistake)
		{
			cout << "There is no such time as " << input << endl;
			cout << "Try again: ";
		}	// since goAgain is initialized as 'y',  will repeat if exception is thrown.
	}
	system("pause");
	return 0;
}

/************************************************
*		string formatTime(string input)
*************************************************/

string formatTime(string input) throw (TimeFormatMistake)
{
	int len = input.length();
	int hr, min;
	// two correct inputs are '0:00' and '00:00'
	// throw exception if length is less than 4 or greater than 5.
	if (len < 4 || len > 5)
		throw TimeFormatMistake();
	else if (len == 4)
	{
		// ensure all user-inputted chars are correct.
		if (!isdigit(input[0]) || input[1] != ':' || !isdigit(input[2]) || !isdigit(input[3]))
			throw TimeFormatMistake();
		// get ints from the user string
		hr = stoi(input.substr(0, 1));
		min = stoi(input.substr(2,4));
	}
	else // len == 5
	{
		// ensure all user-inputted chars are correct.
		if (!isdigit(input[0]) || !isdigit(input[1]) || input[2] != ':' || !isdigit(input[3]) || !isdigit(input[4]))
			throw TimeFormatMistake();
		// get ints from the user string
		hr = stoi(input.substr(0, 2));
		min = stoi(input.substr(3, 5));
	}


	if (hr > 23 || hr < 0 || min > 59 || min < 0)
		throw TimeFormatMistake();

	string ampm = " AM";
	string hours;
	string minutes;
	// if hr is 0, set it to twelve and use "AM"
	if (hr == 0)
		hr = 12;
	// if hr is less than 12, just return the string and add "AM"
	else if (hr < 12)
		return input + " AM";
	// if hr equals 12, just return the string and add "PM"
	else if (hr == 12)
		return input + " PM";
	// if hr is greater than 12, subtract 12 and use "PM"
	else // hr > 12
	{
		hr -= 12;
		ampm = " PM";
	}
	hours = to_string(hr);
	minutes = to_string(min);
	if (min < 10)
		minutes = "0" + minutes;
	string str = hours + ":" + minutes + ampm;
	return str;

}


/************************************************
*		OUTPUT
*************************************************/

//Enter time in 24 - hour notation :
//55555
//There is no such time as 55555
//Try again : Enter time in 24 - hour notation :
//15 : 62
//There is no such time as 15 : 62
//Try again : Enter time in 24 - hour notation :
//25 : 25
//There is no such time as 25 : 25
//Try again : Enter time in 24 - hour notation :
//:
//	There is no such time as :
//Try again : Enter time in 24 - hour notation :
//0 : 00
//That is the same as
//12 : 00 AM
//Again ? (y / n)
//y
//Enter time in 24 - hour notation :
//8 : 35
//That is the same as
//8 : 35 AM
//Again ? (y / n)
//y
//Enter time in 24 - hour notation :
//20 : 08
//That is the same as
//8:08 PM
//Again ? (y / n)
//y
//Enter time in 24 - hour notation :
//23 : 59
//That is the same as
//11 : 59 PM
//Again ? (y / n)
//n
//Press any key to continue . . .

