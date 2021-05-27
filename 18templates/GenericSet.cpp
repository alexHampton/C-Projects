// This is the implementation file for template class GenericSet.
// The interface file is "GenericSet.h"
#ifndef GENERICSET_CPP
#define GENERICSET_CPP

#include <iostream>
using namespace std;
#include "GenericSet.h"

namespace sethampton
{
	template<class ItemType>
	GenericSet<ItemType>::GenericSet() : maxLength(10), currentLength(0)
	{
		list = new ItemType[10];
	}

	template<class ItemType>
	GenericSet<ItemType>::GenericSet(int max) : maxLength(max), currentLength(0)
	{
		list = new ItemType[max];
	}

	template<class ItemType>
	void GenericSet<ItemType>::addItem(ItemType item)
	{
		if (currentLength == maxLength)
		{
			cout << "Error: The list is full.";
			exit(1);
		}
		else if (hasItem(item))
		{
			cout << "The item is already in the list.";			
		}
		else
		{
			list[currentLength] = item;
			currentLength++;
		}
	}

	template<class ItemType>
	void GenericSet<ItemType>::removeItem(ItemType theItem)
	{
		int index = itemIndex(theItem);
		if (index == -1)
		{
			cout << "Error: The item is not in the set.\n";
			exit(1);
		}

		for (index; index < currentLength - 1; index++)
		{ // moves all items down except the last item.
			list[index] = list[index + 1];
		}
		// currentLength points to last item which would then be overwritten by new addItem.
		currentLength--; 
	}

	template<class ItemType>
	ItemType* GenericSet<ItemType>::toItemArray() const
	{
		return list;
	}

	template<class ItemType>
	int GenericSet<ItemType>::length() const
	{
		return currentLength;
	}

	template<class ItemType>
	bool GenericSet<ItemType>::hasItem(ItemType item) const
	{
		return itemIndex(item) == -1 ? false : true;
	}

	template<class ItemType>
	int GenericSet<ItemType>::itemIndex(ItemType item) const
	{
		for (int i = 0; i < currentLength; i++)
		{
			if (list[i] == item)
				return i;
		}
		return -1;
	}
} // sethampton
#endif // !GENERICSET_CPP
