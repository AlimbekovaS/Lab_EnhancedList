#pragma once
#include "Library.h"
template <typename T>
class List
{
protected:
	class Node
	{
	public:
		T date;
		Node* nextPtr;

		Node(T date)
		{
			this->date = date;
			this->nextPtr = nullptr;
		}
	}*firstPtr, *lastPtr;
	Node *curPtr;
	size_t count;
public:
	List()
	{
		firstPtr = nullptr;
		lastPtr = nullptr;
		count = 0;
	}
	void push_back(T date);
	void push_front(T date);
	void print();
	void removeFirst();
	void removeLast();
	bool find(T date);
	//T & operator[](int index);
	size_t size() { return count; }
	virtual ~List();
};

template<typename T>
void List<T>::print()
{
	Node *curPtr = firstPtr;
	cout << curPtr->date << endl;

	while (curPtr != lastPtr)
	{
		curPtr = curPtr->nextPtr;
		cout << curPtr->date << endl;
	}
}

template<typename T>
void List<T>::push_back(T date)
{
	if (count == 0)
	{
		firstPtr = new Node(date);
		lastPtr = firstPtr;
	}
	else
	{
		lastPtr->nextPtr = new Node(date);
		lastPtr = lastPtr->nextPtr;
	}
	count++;
}

template<typename T>
void List<T>::push_front(T date)
{
	if (count == 0)
	{
		firstPtr = new Node(date);
		lastPtr = firstPtr;
	}
	else
	{
		Node *e = new Node(date);
		e->nextPtr = firstPtr;
		firstPtr = e;
	}
	count++;
}

template<typename T>
void List<T>::removeFirst()
{
	if (size() == 1)
	{
		delete firstPtr;
		firstPtr = nullptr;
		lastPtr = nullptr;
	}
	Node *curPtr = firstPtr->nextPtr;
	delete firstPtr;
	firstPtr = curPtr;
	count--;
}
template<typename T>
void List<T>::removeLast()
{
	if (size() == 1)
	{
		delete firstPtr;
		firstPtr = nullptr;
		lastPtr = nullptr;
	}
	else
	{
		Node *curPtr = firstPtr;
		while (curPtr->nextPtr != lastPtr)
		{
			curPtr = curPtr->nextPtr;
		}
		delete lastPtr;
		lastPtr = curPtr;
		curPtr->nextPtr = nullptr;
	}
	count--;
}

template<typename T>
bool List<T>::find(T date)
{
	Node *curPtr = firstPtr;
	while (curPtr != lastPtr)
	{
		if (curPtr->date == date)
			curPtr = curPtr->nextPtr;
	}

	return true;

	return false;

}
//template<typename T>
//T & List<T>::operator[](int index)
//{
//	return[index];
//	// TODO: insert return statement here
//}


template<typename T>
List<T>::~List()
{
	Node *curPtr;

	while (firstPtr != nullptr)
	{
		curPtr = firstPtr->nextPtr;
		delete firstPtr;
		firstPtr = curPtr;
	}
	delete firstPtr;
}



