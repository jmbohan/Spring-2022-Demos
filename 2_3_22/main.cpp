#include "unorderedLinkedList.h"
#include "linkedListIterator.h"
#include "book.h"
#include <iostream>
#include <cstdlib>

using namespace std;



int main() 
{
	string author, title, publisher, subject, callnum, isbn;
	char c = 'Y';
	int numBooks = 1;
	unorderedLinkedList<book> books;// = new book*[numBooks];
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
		
		books.insertLast(book(author, title, subject, publisher, callnum, isbn));
		
		
		cout << endl <<  "Do you want to enter another book: ";
		cin >> c;
		cout << endl << endl;
		c = toupper(c);
		cin.ignore(1000, '\n');
		
		
	}
	books.print();
	cout << endl;
	
	return 0;
}