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
string book::getTitle() const
{
	return title;
}
string book::getAuthor() const
{
	return author;
}
bool book::operator==(const book& o)
{
	return o.author == this->author && o.title == this->title;
}

bool book::operator!=(const book& o)
{
	return !(*this == o);
}

void book::addGenre(string genre)
{
	genreType g = strToGenre.at(genre);
	genres.insert(g);
}

void book::addGenreGroup(string gg)
{
	genreGroupType group = strToGenreGroup.at(gg);
	genres = genreGroupGenres.at(group);
}

ostream& operator<<(ostream& out, const book& b)
{
	out << "Author: " << b.author << endl;
	out << "Title: " << b.title << endl;
	out << "Subject: " << b.subject << endl;
	out << "Publisher: " << b.publisher << endl;
	if(b.genres.size() > 0)
	{
	out << "Genre: ";
	set<genreType>::iterator it = b.genres.begin();
	out << genreToStr.at(*it);
	for(++it; it != b.genres.end(); ++it)
	{
		out << ", " << genreToStr.at(*it);
	}
	}
	out << endl;
	out << "Call Number: " << b.callNum << endl;
	out << "ISBN: " << b.isbn << endl;
	out << "_________________________________" << endl;
	return out;
	
}