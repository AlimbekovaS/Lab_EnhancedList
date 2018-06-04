#pragma once
#include"List.h"
#include"Library.h"
template<typename T>
class EnhancedList :public List<T>
{
public:
	T& operator[](int index)
	{
		int counter = 0;
		curPtr = firstPtr;

		for (int i = 0;i < size();i++)
		{
			if (index == counter)
				return curPtr->date;
			else
			{
				counter++;
				curPtr = curPtr->nextPtr;
			}
		}
	}
};
