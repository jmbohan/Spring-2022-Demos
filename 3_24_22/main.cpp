#include <iostream>
#include "binaryTree.h"
#include "book.h"

using namespace std;

int compareBookByTitle(book book1, book book2);
int compareBookByAuthor(book book1, book book2);
void toUppercase(string&);
int compareInt(int x, int y);

int main()
{
	
	binarySearchTree<int> tree;
	for(int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		tree.insert(x, compareInt);
	}
	
	//cout << tree;
	tree.inorderTraversal();
	cout << endl;
	cout << tree.treeHeight() << endl;
	cout << tree.search(4238336, compareInt) << endl;
	cout << tree.search(115, compareInt) << endl;
	
	cout << tree << endl;
	tree.deleteNode(6930887, compareInt);
	cout << tree << endl;
	
	string author, title, publisher, subject, callnum, isbn;
	char c = 'Y';
	int numBooks = 1;
	binarySearchTree<book> bookTitleTree;
	binarySearchTree<book> bookAuthorTree;
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
		
		bookTitleTree.insert(*b, compareBookByTitle);
		bookAuthorTree.insert(*b, compareBookByAuthor);
		//books.insertLast(book(author, title, subject, publisher, callnum, isbn));
		
		cout << endl <<  *b << endl;
		cout << endl <<  "Do you want to enter another book: ";
		cin >> c;
		cout << endl << endl;
		c = toupper(c);
		cin.ignore(1000, '\n');
		
		
	}
	cout << "Books by Author: " << endl;
	bookAuthorTree.inorderTraversal();
	
	cout << endl << "Books by Title: " << endl;
	bookTitleTree.inorderTraversal();
	
	return 0;
}

int compareBookByTitle(book book1, book book2)
{
	if(book1.getTitle() > book2.getTitle())
		return 1;
	else if(book1.getTitle() < book2.getTitle())
		return -1;
	else 
		return 0;
}

int compareBookByAuthor(book book1, book book2)
{
	if(book1.getAuthor() > book2.getAuthor())
		return 1;
	else if(book1.getAuthor() < book2.getAuthor())
		return -1;
	else 
		return 0;
}

void toUppercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

int compareInt(int x, int y)
{
	if(x > y)
		return 1;
	else if(x < y)
		return -1;
	else 
		return 0;
}