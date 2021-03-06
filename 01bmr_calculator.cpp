// Author: Alex Hampton

#include <iostream>
using namespace std;

//***********************************
//*			FUNCTION main			*
//***********************************

int main()
{
	char gender;										// variable declaration
	int weight, height, age;
	int chocolateBarCalories = 230;
	double bmr, numOfChocBars;
	string pronounOne, pronounTwo;
	char tryAgain;

	

	cout << "Welcome to my BMR calculator.\n";

	do
	{
		cout << "Gender (M or F): ";						// Prompt for Gender
		cin >> gender;

		while (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F')	// Check for valid input
		{
			cout << "Wrong gender input. Please enter again. Gender (M or F): ";		// Continue to prompt for gender until valid. 
			cin >> gender;
		}

		cout << "Weight (in pounds): ";					// Prompt for Weight, Height, and Age.
		cin >> weight;
		cout << "Height (in inches): ";
		cin >> height;										
		cout << "Age (in years): ";						
		cin >> age;											

		if (gender == 'M' || gender == 'm')				// Check if gender is Male
		{
			bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);	// BMR for males
			pronounOne = "He";							// Set male pronouns
			pronounTwo = "his";
		}
		else
		{												// If gender is not male, then it is female.
			bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);	// BMR for females
			pronounOne = "She";							// Set female pronouns.
			pronounTwo = "her";
		}

		numOfChocBars = bmr / chocolateBarCalories;		// Find number of chocolate bars needed.

		cout << pronounOne << " needs " << bmr << " calories to maintain "		// Output the results
			<< pronounTwo << " weight.\n"
			<< "That is about " << numOfChocBars << " chocolate bar's calories.\n\n";

		cout << "Do you want to do another calculation? (Y/N): ";
		cin >> tryAgain;
		cout << endl;
	} while (tryAgain == 'Y' || tryAgain == 'y');		// Repeat loop if user chooses.
	

	cout << "Thanks for using my BMR calculator. Goodbye!\n";


	system("pause");
	return 0;

}

/*			OUTPUT
* Welcome to my BMR calculator.
* Gender (M or F): g
* Wrong gender input. Please enter again (M or F): f
* Weight (in pounds): 130
* Height (in inches): 66
* Age (in years): 32
* She needs 1373.8 calories to maintain her weight.
* That is about 5.97304 chocolate bar's calories.
* 
* Do you want to do another calculation? (Y/N): y
* 
* Gender (M or F): M
* Weight (in pounds): 200
* Height (in inches): 70
* Age (in years): 24
* He needs 2065.8 calories to maintain his weight.
* That is about 8.98174 chocolate bar's calories.
* 
* Do you want to do another calculation?(Y/N): n
* 
* Thanks for using my BMR calculator. Goodbye!
*/