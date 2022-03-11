#include "searchSort.h"
#include "unorderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <climits>


using namespace std;

int getInput(string, bool (*func)(int, int, int), int x, int y);
int fibNum(int, int, int, int[]);
void moveDisks(int count, char source, char destination, char spare);
bool intGreaterThan0(int, int, int);
bool intInRange(int n, int lower, int upper);

int main()
{
	int firstNum, secondNum;
	int current;
	int counter;
	int nthFib;
	int * sequence;
	
	firstNum = getInput("Enter the first Fibonacci number: ", intInRange, 0, 10);
	secondNum = getInput("Enter the second Fibonacci number: ", intInRange, 1, 10);
	
	nthFib = getInput("Enter the position of the desired Fibonacci number: ", intGreaterThan0, 0 , 0);
	
	sequence = new int[nthFib];
	sequence[0] = firstNum;
	sequence[1] = secondNum;
	for (int i = 2; i < nthFib; i++)
	{
		sequence[i] = 0;
	}

	/*if (nthFib == 1)
		current = firstNum;
	else if (nthFib == 2)
		current = secondNum;
	else
	{
		counter = 3;
		while (counter <= nthFib)
		{
			current = firstNum + secondNum;
			firstNum = secondNum;
			secondNum = current;
			counter++;
		}
	} */
	
	cout << "The " << nthFib << "th Fibonacci number is " << fibNum(firstNum, secondNum, nthFib, sequence) << endl;

	//moveDisks(12, 'A', 'C', 'B');

	/*ifstream in;
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
	
	in.close();*/
	delete[] sequence;
	return 0;
}

int fibNum(int first, int second, int n, int seq[])
{
	if(n == 1)
		return first;
	else if (n == 2)
		return second;
	else
	{
		if (seq[n-1] == 0)
		{
			seq[n - 1] = fibNum(first, second, n - 1, seq) + fibNum(first, second, n - 2, seq);
		}
		 
			
		return seq[n - 1];
	}
}

void moveDisks(int count, char source, char destination, char spare)
{
	if (count > 0)
	{
		moveDisks(count - 1, source, spare, destination);
		cout << "Move disk " << count << " from " << source << " to " << destination << "." << endl;
		moveDisks(count - 1, spare, destination, source);
	}
}

int getInput(string prompt, bool (*func)(int, int, int), int x, int y)
{
	int searchItem;
	cout << prompt;
	cin >> searchItem;
	cout << endl;
	if(cin && func(searchItem, x, y))
	{
		return searchItem;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return getInput(prompt, func, x, y);
}


bool intGreaterThan0(int n, int, int)
{
	if(n < 0)
		cout << "The number must be greater than 0." << endl;
	return n > 0;
}

bool intInRange(int n, int lower, int upper)
{
	if(n < lower || n > upper)
		cout << "The number should be between " << lower << " and " << upper << endl;
	return n >= lower && n <= upper;
}