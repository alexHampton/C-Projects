// This is the interface file for template class GenericSet.
// The implementation file is "GenericSet.cpp"

#ifndef GENERICSET_H
#define GENERICSET_H

#include <iostream>
using namespace std;

namespace sethampton
{
	template<class ItemType>
	class GenericSet
	{
	public:
		GenericSet();
		// Constructs a set with 10 as maxLength.
		GenericSet(int max);
		// Constructs a set with max as maxLength.

		void addItem(ItemType item);
		// Precondition: ItemType must be able to use == operator to compare items.
		// Postcondition: Adds an item to the list if it is not already included.
		// Produces error if list is already full.

		void removeItem(ItemType theItem);
		// Precondition: ItemType must be able to use == and = operators.
		// Postcondition: Removes item from the list if it is in the list.
		// Produces error if it is not in the list. 

		ItemType* toItemArray() const;
		// Returns the pointer to the array of items.

		int length() const;
		// Returns current amount of items on the list.

		bool hasItem(ItemType item) const;
		// Precondition: ItemType must be able to use == operator to compare items.
		// Postcondition: Returns true if item is in the list. False otherwise.

		int itemIndex(ItemType item) const;
		// Precondition: ItemType must be able to use == operator to compare items.
		// Postcondition: Returns the index of the item if it is in the list.
		// Returns -1 otherwise.

		friend ostream& operator <<(ostream& outs, const GenericSet<ItemType>& set)
		{
			for (int i = 0; i < set.currentLength; i++)
			{
				cout << set.list[i] << " ";
			}
			return outs;
		}

		

	private:
		ItemType* list;
		int maxLength;
		int currentLength;
	};

} // sethampton

#endif // GENERICSET_H