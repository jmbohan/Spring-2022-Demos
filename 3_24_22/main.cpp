#include <iostream>
#include "binaryTree.h"

using namespace std;

int compareBookByTitle(book book1, book book2);
int compareBookByAuthor(book book1, book book2);

int main()
{
	
	binarySearchTree<int> tree;
	for(int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		tree.insert(x);
	}
	
	//cout << tree;
	tree.inorderTraversal();
	cout << endl;
	cout << tree.treeHeight() << endl;
	cout << tree.search(4238336) << endl;
	cout << tree.search(115) << endl;
	
	cout << tree << endl;
	tree.deleteNode(6930887);
	cout << tree << endl;
	/*
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
		
		bookTitleTree.insert(b);
		bookAuthorTree.insert(b);
		//books.insertLast(book(author, title, subject, publisher, callnum, isbn));
		
		cout << endl <<  *b << endl;
		cout << endl <<  "Do you want to enter another book: ";
		cin >> c;
		cout << endl << endl;
		c = toupper(c);
		cin.ignore(1000, '\n');
		
		
	}
 */
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