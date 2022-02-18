#include "book.h"

book::book(string author, string title, string subject, string publisher, string callNum, string isbn)
{
	this->author = author;
	this->title = title;
	this->subject = subject;
	this->publisher = publisher;
	this->callNum = callNum;
	this->isbn = isbn;
	//this->genre = new genreType[numberOfGenre];
//	for(int i = 0; i < numberOfGenre; i++)
//	{
//		this->genre[i] = g[i];
//	}
}
book::book(const book& otherbook)
{
	this->author = otherbook.author;
	this->title = otherbook.title;
	this->subject = otherbook.subject;
	this->publisher = otherbook.publisher;
	this->callNum = otherbook.callNum;
	this->isbn = otherbook.isbn;
}
book::~book()
 {
	//cout << "Cleaning up " << title << endl;
//	delete [] genre;
}

bool book::operator==(const book& o)
{
	return o.author == this->author && o.title == this->title;
}

bool book::operator!=(const book& o)
{
	return !(*this == o);
}

ostream& operator<<(ostream& out, const book& b)
{
	out << "Author: " << b.author << endl;
	out << "Title: " << b.title << endl;
	out << "Subject: " << b.subject << endl;
	out << "ISBN: " << b.isbn << endl;
	out << "_________________________________" << endl;
	return out;
	
}