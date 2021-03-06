// Author: Alex Hampton


#include <iostream>

using namespace std;


/**************************************************************
 *				PROTOTYPING									  *
 **************************************************************/


int sum(int n);
// pre-condition: takes in a positive integer.
// post-condition: Recursively returns the sum of all 
// integers from 1 to n.

int str_length(char s[], int counter);
// pre-condition: takes in a cstring.
// post-condition: iteratively returns the length of the string.

// UNDEFINED FUNCTION
//int str_length(char s[]);
//// pre-condition: takes in a cstring.
//// psot-condition: recursively returns the length of the string.

void newline();
// pre-condition:
// post-condition: discards the ramainder of an input line.




/**************************************************************
 *				FUNCTION main								  *
 **************************************************************/

int main()
{
	int input;
	char s[100];
	char goAgain;

	do
	{

		cout << "Enter a positive integer: ";
		cin >> input;
		cout << "The sum of 1+2+...+" << input << " is: " << sum(input) << endl << endl;
		newline();
	
		cout << "Enter a sentence: ";
		cin.getline(s, 100);

		int length = str_length(s, 100);

		cout << "It contains " << length << " chars, including white spaces\n\n";
		cout << "Do you want to have another run? (y/n): ";
		cin >> goAgain;
		newline();
		cout << endl;

	} while (goAgain == 'Y' || goAgain == 'y');
	

	system("pause");
	return 0;
}


/**************************************************************
 *				FUNCTION sum								  *
 **************************************************************/

int sum(int n)
{
	if (n == 1)
	{
		return n;
	}
	else
		return (n + sum(n - 1));
}


/**************************************************************
 *				FUNCTION str_length							  *
 **************************************************************/

int str_length(char s[], int counter)
{
	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

//int str_length(char s[])
//{
//	int counter = 0;
//	if (s[counter] == '\0')
//		return 0;
//	else
//	{
//		return 1; //+  str_length()
//	}
//
//}

/**************************************************************
 *				FUNCTION newline							  *
 **************************************************************/

void newline()
{
	char nextChar;
	do
	{
		cin.get(nextChar);
	} while (nextChar != '\n');
}



/**************************************************************
 *				OUTPUT										  *
 **************************************************************/

/*
Enter a positive integer: 10
The sum of 1+2+...+10 is: 55

Enter a sentence: Hello World!
It contains 12 chars, including white spaces

Do you want to have another run? (y/n): y

Enter a positive integer: 100
The sum of 1+2+...+100 is: 5050

Enter a sentence: I love programming!
It contains 19 chars, including white spaces

Do you want to have another run? (y/n): n

Press any key to continue . . .
*/