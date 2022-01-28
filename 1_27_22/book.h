#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

enum genreType {NONFICTION, FICTION, SCIFI, CHILD, HORROR, FANTASY, AUTOBIO, BIO};

const double PI = 3.14;
class book
{
public:
	book(string, string, string, string, string, string);
	~book();
	friend ostream& operator<<(ostream&, const book&);
private:
	string author;
	string title;
	string subject;
	//genreType* genre;
	string publisher;
	string callNum;
	string isbn;
	
};

#endif