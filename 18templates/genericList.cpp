// This is the implementation file genericList.cpp
// This is the implementation of the class template named GenericList.
// The interface for the class template GenericList is in the header
// file genericList.h.
#ifndef GENERICLIST_CPP
#define GENERICLIST_CPP
#include <iostream>
#include <cstdlib>
#include "genericList.h"
using namespace std;

namespace listhampton
{
	template<class ItemType>
	GenericList<ItemType>::GenericList(int max)
		: maxLength(max), currentLength(0)
	{
		item = new ItemType[max];
	}

	template<class ItemType>
	GenericList<ItemType>::~GenericList()
	{
		delete[] item;
	}

	template<class ItemType>
	int GenericList<ItemType>::length() const { return currentLength; }

	template<class ItemType>
	void GenericList<ItemType>::add(ItemType newItem)
	{
		if (full())
		{
			cout << "Error: adding to a full list.\n";
			exit(1);
		}
		else
		{
			item[currentLength] = newItem;
			currentLength++;
		}
	}

	template<class ItemType>
	bool GenericList<ItemType>::full() const
	{
		return (currentLength == maxLength);
	}

	template<class ItemType>
	void GenericList<ItemType>::erase()
	{
		currentLength = 0;
	}
}// listhampton

#endif // !GENERICLIST_CPP