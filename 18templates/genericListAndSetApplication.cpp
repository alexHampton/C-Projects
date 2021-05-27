// Simple program to demonstrate the use of 
// the class templates GenericList and GenericSet.

#include <iostream>
#include "genericList.h"
#include "GenericSet.h"
#include "genericList.cpp"
#include "GenericSet.cpp"


int main()
{
	listhampton::GenericList<int> firstList(2);
	firstList.add(1);
	firstList.add(2);
	std::cout << "firstList = \n"
		<< firstList;

	listhampton::GenericList<char>secondList(10);
	secondList.add('A');
	secondList.add('B');
	secondList.add('C');
	std::cout << "secondList =\n"
		<< secondList;

	sethampton::GenericSet<int> set1;
	set1.addItem(5);
	set1.addItem(6);
	set1.addItem(7);

	std::cout << "set1: " << set1 << endl;

	system("pause");
	return 0;
}
