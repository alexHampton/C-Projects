// This is the application file for Book Project
// This uses the Book class found in 
// Book.h (interface file) and Book.cpp (implementation file).

// This program demonstrates the use of the Standard Template Library.
// Specifically, it utilizes std::vector and std::sort to create
// a simple database of Book objects by using user input.

//Author: Alex Hampton
//04/22/2021

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Book.h"
using std::cin;
using std::cout;
using std::endl;
using namespace bookhampton;
using std::vector;

namespace bookhampton
{
	void printMenu();
	// Prints the menu for the user.

	Book addBook();
	// Takes in user input and returns a Book with the data.

	void printBooks(vector<Book> db);
	// Prints all the Books in db to the screen.
}// bookhampton



int main()
{
	vector<Book> database;
	char userChar = '0';
	while (userChar != '3')
	{
		do
		{
			printMenu();
			cin >> userChar;
			if (userChar < '1' || userChar > '3')	// input validation
				cout << "Error: Please choose 1, 2, or 3\n";
		} while (userChar != '1' && userChar != '2' && userChar != '3'); // input validation

		switch (userChar)
		{
		case '1':
			database.push_back(addBook());
			std::sort(database.begin(), database.end());
			break;
		case '2':
			printBooks(database);
			break;
		default:
			break;
		}
	}

	system("pause");

}

/**********************************************
*		HELPER FUNCTIONS
***********************************************/


namespace bookhampton
{
	void printMenu()
	{
		cout << endl;
		cout << "Select from the following choices:\n";
		cout << "1.\tAdd new book\n";
		cout << "2.\tPrint listing sorted by author\n";
		cout << "3.\tQuit\n";
	}

	Book addBook()
	{
		using std::getline;
		string junk, title, author, date;
		cout << "Enter title:\n";
		getline(cin, junk);
		getline(cin, title);
		cout << "Enter author (last name, first name):\n";
		getline(cin, author);
		cout << "Enter date:\n";
		getline(cin, date);

		return Book(author, date, title);
	}

	void printBooks(vector<Book> db)
	{
		cout << "The books entered so far are:\n";
		vector<Book>::const_iterator i = db.begin();
		for (i; i != db.end(); i++)
		{
			cout << "\t" << i->getAuthor() << ". "
				<< i->getTitle() << ". "
				<< i->getPublicationDate() << ".\n";
		}
	}
}// bookhampton


/**********************************************
*		OUTPUT
***********************************************/


//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//1
//Enter title :
//Bobbing For Hope
//Enter author(last name, first name) :
//	Hope, Bob
//	Enter date :
//2000
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//1
//Enter title :
//On Your Mark, Get Set, Remark!
//Enter author(last name, first name) :
//	Aardvark, Clark
//	Enter date :
//2010
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//2
//The books entered so far are :
//Aardvark, Clark.On Your Mark, Get Set, Remark!. 2010.
//Hope, Bob.Bobbing For Hope. 2000.
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//1
//Enter title :
//Hoping For Bob
//Enter author(last name, first name) :
//	Hope, Bob
//	Enter date :
//2001
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//1
//Enter title :
//Star Tours, A Bob Hope
//Enter author(last name, first name) :
//	Pope, Rob
//	Enter date :
//2002
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//2
//The books entered so far are :
//Aardvark, Clark.On Your Mark, Get Set, Remark!. 2010.
//Hope, Bob.Bobbing For Hope. 2000.
//Hope, Bob.Hoping For Bob. 2001.
//Pope, Rob.Star Tours, A Bob Hope. 2002.
//
//Select from the following choices :
//1.      Add new book
//2.      Print listing sorted by author
//3.      Quit
//3
//Press any key to continue . . .