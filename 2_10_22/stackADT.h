#ifndef STACKADT_H
#define STACKADT_H

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type&) = 0;
	virtual Type top() const = 0;
	virtual Type pop() = 0;
	
};








#endif