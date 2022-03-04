#include "searchSort.h"
#include "unorderedLinkedList.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	ifstream in;
	in.open("input.txt");
	
	unorderedLinkedList<int> l;
	int size = 1000000;
	for(int i = 0; i < size; i++)
	{
		int x; 
		in >> x;
		l.insertLast(x);
	}
	
	//l.print();
	int searchItem = 9098;
	int pos = seqSearch(l, searchItem);
	
	if(pos > 0)
		cout << "Found "<< searchItem << " at position " << pos << endl;
	else
		cout << "Did not find " << searchItem << endl;
	//bubbleSort(l);
	//insertionSort(l);
	//pos = binarySearch(l, searchItem);
	if(pos > 0)
		cout << "Found "<< searchItem << " at position " << pos << endl;
	else
		cout << "Did not find " << searchItem << endl;
	
	int * l2;
	l2 = new int[size];
	in.seekg(0);
	for(int i = 0; i < size; i++)
	{
		int x;
		in >> x;
		l2[i] = x;
		//cout << l2[i] << endl;
	}
	
	pos = seqSearch(l2, size, searchItem);
	if(pos > 0)
		cout << "Found "<< searchItem << " at position " << pos << endl;
	else
		cout << "Did not find " << searchItem << endl;
	
	
	//bubbleSort(l2, size);
	//selectionSort(l2, size);
	mergeSort(l2, size);
	pos = binarySearch(l2, size, searchItem);
	if(pos > 0)
		cout << "Found "<< searchItem << " at position " << pos << endl;
	else
		cout << "Did not find " << searchItem << endl;
	
	in.close();
	return 0;
}