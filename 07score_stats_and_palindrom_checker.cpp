// Author: Alex Hamptpon


#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**************************************************************
 *						PROTOTYPING                           *
 **************************************************************/

void get_scores(vector<int>& v);
// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function

void print_stats(vector<int>& v);
// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average

int max_value(vector<int> v);
// pre-condition: takes in a vector of type int
// post-condition: returns the maximum value in the vector.

int min_value(vector<int> v);
// pre-condition: takes in a vector of type int
// post-condition: returns the minimum value in the vector.

double average_value(vector<int> v);
// pre-condition: takes in a vector of type int
// post-condition: returns the average of the values as a double

bool is_palindrome(string sentence);
// return true if the sentence is a palindrome;
// false otherwise

void remove_punctuation(string& sentence);
// pre-condition: takes in a string as an argument.
// post-condition: alters the string to remove numbers, punctuation, and whitespace.

void make_lowercase(string& sentence);
// pre-condition: takes in a string as an argument.
// post-condition: all letters turned into lowercase.

string reverse(string sentence);
// pre-condition: takes in a string as an argument. 
// Expected to be used after punctuation has been removed
// and string has been made into lowercase.
// post-condition: returns the string in reverse order.

void newLine();
// Pre-condition: user has provided input.
// post-condition: discards input until on the next line of input.


/**************************************************************
 *				FUNCTION main		                          *
 **************************************************************/

int main()
{
	using namespace std;

	/****************************
	 *	Problem 1: Stats		*
	 ****************************/

	vector<int> scores;
	char input;
	do
	{
		get_scores(scores);
		if (scores.size() == 0)								// Exception handling if no scores given.
			cout << "There are no scores.\n";
		else
			print_stats(scores);

		cout << "\nDo you want to try another set of scores? (y/n): ";
		cin >> input;

		newLine();											// discards the rest of the line of input
		cout << endl;
	} while (input == 'Y' || input == 'y');




	/*****************************
	 *	Problem 2: Palindrome	 *
	 *****************************/

	string line;
	
	do
	{
		cout << "\nEnter a sentence: ";
		getline(cin, line);
		if (is_palindrome(line))
			cout << "\"" << line << "\" is " << "a palindrome.\n";
		else
			cout << "\"" << line << "\" is " << "not a palindrome.\n";
		cout << endl;

		cout << "Do you want to try another sentence? (y/n): ";
		cin >> input;

		newLine();										// discards the rest of the line of input
		cout << endl;
	} while (input == 'Y' || input == 'y');


	cout << "Goodbye.\n";

	system("pause");
	return 0;
}


/**************************************************************
 *				FUNCTION get_scores		                      *
 **************************************************************/

void get_scores(vector<int>& v)
{
	v.clear();
	int next;

	cout << "Enter scores, enter -1 to stop:\n";
	cin >> next;
	while (next > 0)
	{
		v.push_back(next);
		cin >> next;
	}
}

/**************************************************************
 *				FUNCTION print_stats		                      *
 **************************************************************/

void print_stats(vector<int>& v)
{
	int max = max_value(v);
	int min = min_value(v);
	double ave = average_value(v);

	cout << "There are a total of " << v.size() << " scores.\n"
		<< "The highest score is: " << max << endl
		<< "The lowest score is: " << min << endl
		<< "The average score is: " << ave << endl;
}


/**************************************************************
 *				FUNCTION average_value	                      *
 **************************************************************/

double average_value(vector<int> v)
{
	double sum(0);

	for (int i = 0; i < v.size(); i++)
	{
		sum += static_cast<double>(v[i]);
	}

	return sum / v.size();

}


/**************************************************************
 *				FUNCTION max_value		                      *
 **************************************************************/

int max_value(vector<int> v)
{
	int max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	return max;
}


/**************************************************************
 *				FUNCTION min_value		                      *
 **************************************************************/

int min_value(vector<int> v)
{
	int min = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	return min;
}


/**************************************************************
 *				FUNCTION is_palindrome                        *
 **************************************************************/

bool is_palindrome(string sentence)
{
	remove_punctuation(sentence);
	make_lowercase(sentence);

	string reversedString = reverse(sentence);
	if (reversedString == sentence)
		return true;
	else
		return false;
}


/**************************************************************
 *				FUNCTION remove_punctuation                   *
 **************************************************************/

void remove_punctuation(string& sentence)
{
	for (int idx = 0; idx < sentence.length(); idx++)
	{
		if (!isalpha(sentence[idx]))
		{
			sentence.erase(idx, 1);
			idx -= 1;
		}
	}
}


/**************************************************************
 *				FUNCTION make_lowercase                       *
 **************************************************************/

void make_lowercase(string& sentence)
{
	for (int idx = 0; idx < sentence.length(); idx++)
	{
			sentence[idx] = tolower(sentence[idx]);
	}
}


/**************************************************************
 *				FUNCTION reverse	                          *
 **************************************************************/

string reverse(string sentence)
{
	string reverse_string = "";
	for (int i = 0; i < sentence.length(); i++)
	{
		reverse_string = sentence[i] + reverse_string;
	}
	return reverse_string;

}


/**************************************************************
 *				FUNCTION newLine							  *
 **************************************************************/

void newLine()
{
	char nextChar;
	do
	{
		cin.get(nextChar);
	} while (nextChar != '\n');
}





/**************************************************************
 *						OUTPUT	                              *
 **************************************************************/

/*
Enter scores, enter -1 to stop:
87
98
65
78
88
93
-1
There are a total of 6 scores.
The highest score is: 98
The lowest score is: 65
The average score is: 84.8333

Do you want to try another set of scores? (y/n): y

Enter scores, enter -1 to stop:
-1
There are no scores.

Do you want to try another set of scores? (y/n): n


Enter a sentence: A nut for a jar... of tuna
"A nut for a jar... of tuna" is a palindrome.

Do you want to try another sentence? (y/n): y


Enter a sentence: Hello world
"Hello world" is not a palindrome.

Do you want to try another sentence? (y/n): n

Goodbye.
Press any key to continue . . .
*/