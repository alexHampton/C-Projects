// This is the interface file Book.h.
// The implementation for this file is found 
// in Book.cpp.

//Author: Alex Hampton
//04/22/2021


#ifndef BOOK_H
#define BOOK_H
#include <string>

using std::string;
namespace bookhampton
{
	class Book
	{
	public:
		friend bool operator <(const Book& theLeft, const Book& theRight);
		// Compares Book theLeft to Book theRight and evaulates to True if
		// theLeft.author < theRight.author.
		// Used to sort Books by author.

		Book();
		// Default Constructor. Sets all values to an empty string.

		Book(string theAuthor, string thePubDate, string theTitle);
		// Constructor. Sets all values to respective strings.

		// Accessor (getter) member functions
		string getAuthor() const;
		string getPublicationDate() const;
		string getTitle() const;

		// Mutator (setter) member functions
		void setAuthor(string newAuthor);
		void setPublicationDate(string newPubDate);
		void setTitle(string newTitle);

	private:
		string author; // Author of the Book.
		string publicationDate; // Date of the Book.
		string title; // Title of the Book.
	};

	
} // bookhampton
#endif // !BOOK_H
