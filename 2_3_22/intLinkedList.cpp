#include "intLinkedList.h"
#include <iostream>
using namespace std;

intLinkedList::intLinkedList()
{
	head = nullptr;
	tail = nullptr;
	numNodes = 0;
}

void intLinkedList::insert(int num)
{
	nodeType * newNode = new nodeType;
	newNode->info = num;
	newNode->link = nullptr;
	
	if(head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		if(newNode->info < head->info)
		{
			newNode->link = head;
			head = newNode;
		} else if(newNode->info > tail->info)
		{
			tail->link = newNode;
			tail = newNode;
		}
		else
		{
		nodeType * current; 
		nodeType * trailCurrent;
		trailCurrent = head;
		current = head->link;
		while(newNode->info > current->info && current != nullptr)
		{
			trailCurrent = current;
			current = current->link;
		}
		if(current == nullptr)
		{
			tail->link = newNode;
			tail = newNode;
		}
		else 
		{
			newNode->link = current;
			trailCurrent->link = newNode;
		}
			
		}
		
	}
}

void intLinkedList::print()
{
	nodeType * current;
	current = head;
	while(current != nullptr)
	{
		cout << current->info << " ";
		current = current->link;
	}
}