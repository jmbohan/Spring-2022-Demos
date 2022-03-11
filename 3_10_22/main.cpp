#include "searchSort.h"
#include "unorderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <climits>


using namespace std;

int getInput(string);

int main()
{
	ifstream in;
	in.open("input.txt");
	
	int size = 1000;

	int searchItem = 0;
	int pos = -1;

	int * l2;
	l2 = new int[size];

	for(int i = 0; i < size; i++)
	{
		int x;
		in >> x;
		l2[i] = x;
		//cout << l2[i] << endl;
	}
	
	searchItem = getInput("Enter a number to search for in the list: ");
	
	mergeSort(l2, size);
	pos = binarySearch(l2, size, searchItem);
	if(pos > 0)
		cout << "Found "<< searchItem << " at position " << pos << endl;
	else
		cout << "Did not find " << searchItem << endl;
	
	in.close();
	return 0;
}

int getInput(string prompt)
{
	int searchItem;
	cout << prompt;
	cin >> searchItem;
	cout << endl;
	if(cin)
	{
		return searchItem;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return getInput(prompt);
}
