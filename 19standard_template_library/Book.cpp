// This is the implementation file for the header
// file Book.h.

//Author: Alex Hampton
//04/22/2021

#include "Book.h"

namespace bookhampton
{
	bool operator <(const Book& theLeft, const Book& theRight)
	{
		return theLeft.author < theRight.author;
	}

	Book::Book() : author(""), publicationDate(""), title("") {}
	Book::Book(string theAuthor, string thePubDate, string theTitle)
		: author(theAuthor), publicationDate(thePubDate), title(theTitle) {}

	string Book::getAuthor() const { return author; }
	string Book::getPublicationDate() const { return publicationDate; }
	string Book::getTitle() const { return title; }

	void Book::setAuthor(string newAuthor) { author = newAuthor; }
	void Book::setPublicationDate(string newPubDate) { publicationDate = newPubDate; }
	void Book::setTitle(string newTitle) { title = newTitle; }

}






