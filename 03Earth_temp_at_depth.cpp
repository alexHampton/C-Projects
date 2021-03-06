// Author: Alex Hampton

#include <iostream>

void print_introduction();							// declare functions / prototyping			
double celsius_at_depth(double depth);				// returns temperature in celsius at given depth of the Earth.						
double celsius_to_fahrenheit(double celsius);		// converts given temperature from celsius to fahrenheit.
void print_conclusion(double depth);
// Calls celsius_at_depth and celsius_to_fahrenheit,
// then prints a conclusion of the temperature at the userDepth.


/***************************************************************
*					FUNCTION main							   *
****************************************************************/

int main()
{
	using namespace std;

	char userInput;

	print_introduction();			// call function

	do
	{
		int userDepth;

		cout << "Enter a depth in KM: ";		// Ask for input
		cin >> userDepth;						// get input

		cout << endl;
		print_conclusion(userDepth);		
		cout << endl;

		cout << "Would you like to do it again? (Y/N): ";	
		cin >> userInput;
		cout << endl;

	} while (userInput == 'Y' || userInput == 'y'); // repeat
	

	cout << "Goodbye.\n";

	system("pause");
	return 0;

}


/***************************************************************
*				FUNCTION print_introduction					   *
****************************************************************/

void print_introduction()
{
	using namespace std;
	cout << "Hello! The program will tell you the temperature of the earth at any depth.\n\n";
}


/***************************************************************
*				FUNCTION celsius_at_depth					   *
****************************************************************/

double celsius_at_depth(double depth)
{
	double celsius;
	celsius = 10 * depth + 20;
	return celsius;
}


/***************************************************************
*				FUNCTION celsius_to_fahrenheit			       *
****************************************************************/

double celsius_to_fahrenheit(double celsius)
{
	double fahrenheit = 1.8 * celsius + 32;
	return fahrenheit;
}


/***************************************************************
*				FUNCTION print_conclusion					   *
****************************************************************/

void print_conclusion(double depth)
{
	using namespace std;
	double userCelsius = celsius_at_depth(depth);					// assign variables to function calls.
	double userFahrenheit = celsius_to_fahrenheit(userCelsius);

	cout << "The temperature of the earth at a depth of " << depth << " KM is "
		<< userCelsius << " in Celsius, and " << userFahrenheit << " in Fahrenheit.\n";
}


/***************************************************************
*							OUTPUT							   *
****************************************************************/

/*

Hello! The program will tell you the temperature of the earth at any dpeth.

Enter a depth in KM: 10

The temperature of the earth at a dpeth of 10 KM in 120 Celsius, and 248 in Fahrenheit.

Would you like ot do it again? (Y/N): y

Enter a depth in KM: 20

The temperature of the earth at a dapth of 20 KM is 220 Celsius, and 428 in Fahrenheit.

Would you like to do it again? (Y/N): n

Goodbye.


*/
