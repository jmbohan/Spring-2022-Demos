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

book::~book()
 {
	//cout << "Cleaning up " << title << endl;
//	delete [] genre;
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