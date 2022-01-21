#ifndef BOOK_H
#define BOOK_H
#include <string>

using std::string;

enum genreType {NONFICTION, FICTION, SCIFI, CHILD, HORROR, FANTASY, AUTOBIO, BIO};


class book
{
public:
	book(string, string, string, genreType[],int, string, string, string);
	~book();
private:
	string author;
	string title;
	string subject;
	genreType* genre;
	string publisher;
	string callNum;
	string isbn;
	
};

#endif