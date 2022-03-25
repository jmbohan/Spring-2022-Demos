#ifndef BINARY_H
#define BINARY_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include "linkedQueue.h"

using namespace std;

template <class Type>
struct binaryNode
{
	Type * info;
	binaryNode<Type> *lLink;
	binaryNode<Type> *rLink;
	~binaryNode() { delete info;};
};

template <class Type>
class binarySearchTree
{
public: 
	const binarySearchTree<Type>& operator= (const binarySearchTree<Type>&);
	bool isEmpty() const;
	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	int treeHeight() const;
	int treeNodeCount() const;
	int treeLeavesCount() const;
	void destroyTree();
	bool search(const Type& searchItem) const;
	void insert(const Type& insertItem);
	void deleteNode(const Type& deleteItem);
	binarySearchTree(const binarySearchTree<Type>& otherTree);
	binarySearchTree();
	~binarySearchTree();
	template <class T> friend ostream& operator<<(ostream& out, const binarySearchTree<T>& tree);
private: 
	binaryNode<Type> *root;
	void inorder(binaryNode<Type> *p) const;
	void preorder(binaryNode<Type> *p) const;
	void postorder(binaryNode<Type> *p) const;
	int height(binaryNode<Type> *p) const;
	int max(int x, int y) const;
	int nodeCount(binaryNode<Type> *p) const;
	int leavesCount(nodeType<Type> *p) const;
	void copyTree(binaryNode<Type> * &copiedTreeRoot, binaryNode<Type> * otherTreeRoot);
	string printTree() const;
	void destroy(binaryNode<Type> * &p);
	bool search(const Type& searchItem, binaryNode<Type> *p) const;
	void deleteFromTree(binaryNode<Type> * &p);
};

template <class Type>
bool binarySearchTree<Type>::isEmpty() const
{
	return (root == nullptr);
}

template <class Type>
void binarySearchTree<Type>::inorderTraversal() const
{
	inorder(root);
}

template <class Type>
void binarySearchTree<Type>::inorder(binaryNode<Type> *p) const
{
	if(p != nullptr)
	{
		inorder(p->lLink);
		cout << *p->info << " ";
		inorder(p->rLink);
	}
}

template <class Type>
void binarySearchTree<Type>::preorderTraversal() const
{
	preorder(root);
}

template <class Type>
void binarySearchTree<Type>::preorder(binaryNode<Type> *p) const
{
	if(p != nullptr)
	{
		cout << *p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}
template <class Type>
void binarySearchTree<Type>::postorderTraversal() const
{
	postorder(root);
}

template <class Type>
void binarySearchTree<Type>::postorder(binaryNode<Type> *p) const
{
	if(p != nullptr)
	{
		postrder(p->lLink);
		
		postorder(p->rLink);
		cout << *p->info << " ";
	}
}

template <class Type>
int binarySearchTree<Type>::height(binaryNode<Type> *p) const
{
	if(p == nullptr)
	{
		return 0;
	}
	else 
		return 1 + max(height(p->lLink), height(p->rLink));
}

template <class Type>
int binarySearchTree<Type>::treeHeight() const 
{
	return height(root);
}
template <class Type>
int binarySearchTree<Type>::max(int x, int y) const
{
	if(x >= y)
		return x;
	else 
		return y;
}

template <class Type>
void binarySearchTree<Type>::copyTree(binaryNode<Type> * &copiedTreeRoot, binaryNode<Type> * otherTreeRoot)
{
	if(otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	else
	{
		copiedTreeRoot = new binaryNode<Type>;
		copiedTreeRoot->info = new Type(*otherTreeRoot->info);
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}

template <class Type>
void binarySearchTree<Type>::insert(const Type& insertItem)
{
	binaryNode<Type> *current;
	binaryNode<Type> *trailCurrent = nullptr;
	binaryNode<Type> *newNode;
	
	newNode = new binaryNode<Type>;
	newNode->info = new Type(insertItem);
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	
	if(root == nullptr)
		root = newNode;
	else 
	{
		current = root;
		while(current != nullptr)
		{
			trailCurrent = current;
			if(*current->info == insertItem)
			{
				cout << "The item is already in the tree" << endl;
				return;
			}
			else if (*current->info > insertItem)
				current = current->lLink;
			else 
				current = current->rLink;
		}
		if(*trailCurrent->info > insertItem)
			trailCurrent->lLink = newNode;
		else
			trailCurrent->rLink = newNode;
	}
}

template <class Type>
void binarySearchTree<Type>::destroy(binaryNode<Type> * &p)
{
	if(p!= nullptr)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
	}
}

template <class Type>
void binarySearchTree<Type>::destroyTree()
{
	destroy(root);
}

template <class Type>
binarySearchTree<Type>::binarySearchTree()
{
	root = nullptr;
}

template <class Type>
binarySearchTree<Type>::~binarySearchTree()
{
	destroy(root);
}

template <class Type>
binarySearchTree<Type>::binarySearchTree(const binarySearchTree<Type>& otherTree)
{
	if(otherTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root, otherTree.root);
}

template <class Type>
const binarySearchTree<Type>& binarySearchTree<Type>::operator=(const binarySearchTree<Type>& otherTree)
{
	if(this != &otherTree)
	{
		if(root != nullptr)
			destroy(root);
		if(otherTree.root == nullptr)
			root = nullptr;
		else
		copyTree(root, otherTree.root);
	}
	
	return *this;
	
}

template <class Type>
bool binarySearchTree<Type>::search(const Type& searchItem) const
{
	return search(searchItem, root);
}

template <class Type>
bool binarySearchTree<Type>::search(const Type& searchItem, binaryNode<Type> * p) const
{
	if(p == nullptr)
		return false;
	else
	{
		if(*p->info == searchItem)
			return true;
		else if (searchItem < *p->info)
			return search(searchItem, p->lLink);
		else 
			return search(searchItem, p->rLink);
		
	}
}


template <class Type>
void binarySearchTree<Type>::deleteFromTree(binaryNode<Type> * &p)
{
	binaryNode<Type> *current;
	binaryNode<Type> *trailCurrent;
	binaryNode<Type> *temp;
	
	if(p == nullptr)
		cout << "The item is not in the list" << endl;
	else if (p->lLink == nullptr && p->rLink == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if (p->lLink == nullptr)
	{
		temp = p;
		p = temp->rLink;
		delete temp;
	}
	else if(p->rLink == nullptr)
	{
		temp = p;
		p = temp->lLink;
		delete temp;
	}
	else 
	{
		current = p->lLink;
		trailCurrent = nullptr;
		while(current->rLink != nullptr)
		{
			trailCurrent = current;
			current = current->rLink;
		}
		Type * temp;
		temp = p->info;
		p->info = current->info;
		current->info = temp;
		if(trailCurrent == nullptr)
			p->lLink = current->lLink;
		else 
			trailCurrent->rLink = current->lLink;
		delete current;
	}
}

template <class Type>
void binarySearchTree<Type>::deleteNode(const Type& deleteItem)
{
	binaryNode<Type> * current;
	binaryNode<Type> * trailCurrent;
	bool found = false;
	
	if(root == nullptr)
		cout << "Tree is empty" << endl;
	else 
	{
		current = root;
		trailCurrent = root;
		while(current != nullptr && !found)
		{
			if(*current->info == deleteItem)
				found = true;
			else 
			{
				trailCurrent = current;
				if(*current->info > deleteItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}
		if(current == nullptr || !found)
			cout << "The item is not in the tree" << endl;
		else 
		{
			if(current == root)
				deleteFromTree(root);
			else if(*trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->lLink);
			else 
				deleteFromTree(trailCurrent->rLink);
		}
	}
}

























template<class elemType>
string binarySearchTree<elemType>::printTree() const
{
	ostringstream out;
	struct nodeDepth
	{
		binaryNode<elemType>* n;
    	int lvl;
    	//node_depth(node<elemType>* n_, int lvl_) : n(n_), lvl(lvl_) {}
	};
	int depth = height(root);
	int last_lvl = 0;
	int offset = (1 << depth) - 1;
	linkedQueueType<nodeDepth> nodes;
	nodeDepth rootDepth;
	rootDepth.n = root;
	rootDepth.lvl = last_lvl;
	nodes.enqueue(rootDepth);
	while(!nodes.isEmptyQueue())
	{
		nodeDepth current = nodes.front();
		if(last_lvl != current.lvl)
		{
			out << endl;
			last_lvl = current.lvl;
    		offset = (1 << (depth - current.lvl)) - 1;
			
		}
		if(current.n != nullptr)
		{
			out << setw(offset) << " ";
			out << setw(3) << *current.n->info;
			out << setw(offset) << " ";
			nodeDepth left;
			nodeDepth right;
			left.n = current.n->lLink;
			right.n = current.n->rLink;
			left.lvl = last_lvl + 1;
			right.lvl = last_lvl + 1;
			nodes.enqueue(left);
			nodes.enqueue(right);
		} 
		else
		{
			out << setw(offset) << " " << "   ";
			out << setw(offset) << " ";
		}
		nodes.dequeue();
	}
	out << endl;
	
	return out.str();
}

template <class elemType>
ostream& operator<<(ostream& out, const binarySearchTree<elemType>& tree)
{
	out << tree.printTree();
	return out;
}

#endif