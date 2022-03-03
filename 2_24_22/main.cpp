#include "book.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;

void toUppercase(string&);

int main()
{
	string author, title, publisher, subject, callnum, isbn;
	char c = 'Y';
	int numBooks = 1;
	vector<book*> books;
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
		cout << endl;
		
		char g = 'Y';
		book * b = new book(author, title, subject, publisher, callnum, isbn);
		while (g == 'Y')
		{
			int genreChoice;
			cout << "Would you like to enter a" << endl;
			cout << "1. Genre Group" << endl;
			cout << "2. Indvidual Genre" << endl;
			cin >> genreChoice;
			cout << endl;
			if(genreChoice == 1)
			{
				string groupStr;
				cout << "Enter a genre group from the following list (";
				map<genreGroupType, string>::const_iterator it = genreGroupToStr.begin();
				cout << it->second;
				for(++it; it != genreGroupToStr.end(); ++it)
				{
					cout << ", " << it->second;
				}
				getline(cin >> ws, groupStr);
				toUppercase(groupStr);
				try 
				{
					b->addGenreGroup(groupStr);
				}
				catch(out_of_range e)
				{
					cout << e.what() << endl;
				}
				
			} 
			else 
			{
				string genreStr;
				cout << "Enter a genre from the following list (";
				map<genreType,string>::const_iterator it = genreToStr.begin();
				cout << it->second;
				for (++it; it != genreToStr.end(); ++it)
				{
					cout << ", " << it->second;
				}
				cout << "): ";
				getline(cin >> ws, genreStr);
				cout << endl;
				toUppercase(genreStr);
				b->addGenre(genreStr);
			}
			cout << "Would you like to enter another genre: ";
			cin >> g;
			cout << endl;
			g = toupper(g);
			
		}
		
		books.push_back(b);
		//books.insertLast(book(author, title, subject, publisher, callnum, isbn));
		
		cout << endl <<  *b << endl;
		cout << endl <<  "Do you want to enter another book: ";
		cin >> c;
		cout << endl << endl;
		c = toupper(c);
		cin.ignore(1000, '\n');
		
		
	}
	for(int i = 0; i < books.size(); i++)
	{
		cout << *books[i] << endl;
	}
	cout << endl;

	return 0;
}


void toUppercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}


























