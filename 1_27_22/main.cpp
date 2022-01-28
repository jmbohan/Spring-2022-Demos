#include <iostream>
#include <cctype>
#include "book.h"

using namespace std;



int main() 
{
	string author, title, publisher, subject, callnum, isbn;
	char c = 'Y';
	int numBooks = 1;
	book ** books = new book*[numBooks];
	for(int i = 0; i < numBooks; i++)
	{
		books[i] = 0;
	}
	while(c == 'Y')
	{
		cout << "Enter the book author: ";
		getline(cin >> ws, author);
		cout << endl << "Enter the book title: ";
		getline(cin, title);
		cout << endl << "Enter the book subject: ";
		getline(cin, subject);
		cout << endl << "Enter the book publisher: ";
		getline(cin, publisher);
		cout << endl << "Enter the call number: ";
		getline(cin, callnum);
		cout << endl << "Enter the isbn: "; 
		getline(cin, isbn);
		
		books[numBooks - 1] = new book(author, title, subject, publisher, callnum, isbn);
		
		
		cout << endl <<  "Do you want to enter another book: ";
		cin >> c;
		cout << endl << endl;
		c = toupper(c);
		cin.ignore(1000, '\n');
		
		if(c == 'Y')
		{
			book ** cpy = new book*[++numBooks];
			for(int i = 0; i < numBooks; i++)
			{
				cpy[i] = new book(*books[i]);
				cpy[i] = books[i];
			}
			delete [] books;
			books = cpy;
			delete [] cpy;
		}
	}
	for(int i = 0; i < numBooks; i++)
	{
		cout << *books[i] << endl;
	}
	for(int i = 0; i < numBooks; i++)
	{
		delete books[i];
		books[i] = nullptr;
	}
	delete [] books;
	books = NULL;
	
	return 0;
}