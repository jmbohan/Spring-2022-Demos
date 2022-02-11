#ifndef STACK_H
#define STACK_H
#include "stackADT.h"
#include <stdexcept>

using std::out_of_range;

template <class Type>
class stackType : public stackADT<Type>
{
public:
	const stackType<Type>& operator=(const stackType<Type>&);
	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	Type pop();
	stackType(int stackSize = 100);
	stackType(const stackType<Type>&);
	~stackType();
private:
	void copyStack(const stackType<Type>&);
	int maxStackSize;
	int stackTop;
	Type ** list;
};

template <class Type>
void stackType<Type>::initializeStack() 
{
	for(int i = 0; i < stackTop; i++)
	{
		delete list[i];
	}
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if(!isFullStack())
	{
		list[stackTop] = new Type(newItem);
		stackTop++;
	} 
	else 
	{
		throw out_of_range("Cannot add to a full stack.");
	}
}

template <class Type>
Type stackType<Type>::top() const
{
	if(stackTop == 0)
		throw out_of_range("Empty Stack");
	return *(list[stackTop - 1]);
}

template <class Type>
Type stackType<Type>::pop()
{
	if(isEmptyStack())
		throw out_of_range("Cannot remove from an empty stack.");
	else
	{
		Type t(*(list[stackTop-1]));
		delete list[stackTop-1];
		stackTop--;
		return t;
	}
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) 
{
	for(int i = 0; i < stackTop; i++)
	{
		delete this->list[i];
	}
	delete [] list;
	
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type*[maxStackSize];
	for(int i = 0; i < stackTop; i++)
	{
		list[i] = new Type(otherStack.list[i]);
	}
}
template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if(stackSize <= 0)
	{
		maxStackSize = 100;
	}
	else 
		maxStackSize = stackSize;
	
	stackTop = 0;
	list = new Type *[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType()
{
	for(int i = 0; i < stackTop; i++)
	{
		delete list[i];
	}
	delete [] list;
	stackTop = 0;
}
template <class Type>
stackType<Type>::stackType(const stackType& otherStack)
{
	list = nullptr;
	copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
	if(this != &otherStack)
		copyStack(otherStack);
	
	return *this;
}






#endif