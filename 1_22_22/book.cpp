#include "book.h"

book::book(string author, string title, string subject, genreType g[],int numberOfGenre, string publisher, string callNum, string isbn)
{
	this->author = author;
	this->title = title;
	this->subject = subject;
	this->publisher = publisher;
	this->callNum = callNum;
	this->isbn = isbn;
	this->genre = new genreType[numberOfGenre];
	for(int i = 0; i < numberOfGenre; i++)
	{
		this->genre[i] = g[i];
	}
}

book::~book()
 {
	//cout << "Cleaning up " << title << endl;
	delete [] genre;
}


