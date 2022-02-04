#ifndef INTLIST_H
#define INTLIST_H

struct nodeType
{
	int info;
	nodeType * link;
};


class intLinkedList
{
	public:
	intLinkedList();
	bool search(int);
	void insert(int);
	void deleteInt(int);
	void print();
	
	private:
	nodeType * head;
	nodeType * tail;
	int numNodes;
	
};






#endif