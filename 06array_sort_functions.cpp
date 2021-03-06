// Author: Alex Hampton

#include <iostream>


/************************************************************************
*								PROTOTYPING								*
*************************************************************************/

void menu();
// precondition: none
// postcondition: prints menu of choices to the screen.

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 
// elements per line

int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If
// the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

int indexOfSmallest(const int arr[], int startIndex, int numberUsed);
// pre-condition: numberUsed is <= size of array arr.
// startIndex is the first index of the array to be sorted.
// post-condition: returns the smallest value within the segment of the array.

void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void swapValues(int&, int&);
// pre-condition: input two integers
// post-condition: Values of variables are swapped using call-by-reference.

void printValues(const int arr[], int size);
// pre-condition: size equals the size of the array.
// post-condition: prints the values of the array to the screen.




/************************************************************************
*				FUNCTION main()											*
*************************************************************************/

int main() 
{
	using namespace std;

	int choice;
	int a[9];
	do 
	{
		system("CLS");
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:												// Uses Linear Search
			{
				fill_array(a, 9);
				cout << "Enter the key you want to search: ";
				int key;
				cin >> key;
				int index = linear_search(a, 9, key);
				if (index == -1)
					cout << "The key " << key << " is not in array\n";
				else
					cout << "The key " << key << " is #" << (index + 1) 
					<< " element in array\n";
					break;
			}
			case 2:												// Uses Select Sort 
			{
				fill_array(a, 9);
				select_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 3:												// Uses Insert Sort
			{
				fill_array(a, 9);
				insert_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 4:												// Uses Bubble Sort
			{
				fill_array(a, 9);
				bubble_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 5:												// Exits program
			{
				cout << "Thank you for using the array functions\n";
				break;
			}
			default:
			{
				cout << "Wrong choice. Please choose from menu: ";
				break;
			}
		}
		system("pause");
	} while (choice != 5);

	
	return 0;
}




/************************************************************************
*				FUNCTION menu											*
*************************************************************************/

void menu()
{
	using namespace std;
	cout << endl;
	cout << "**********  MENU  **********\n";
	cout << "*  1. Linear Search        *\n";
	cout << "*  2. Select Sort          *\n";
	cout << "*  3. Insert Sort          *\n";
	cout << "*  4. Bubble Sort          *\n";
	cout << "*  5. End Program          *\n";
	cout << "****************************\n";

}


/************************************************************************
*				FUNCTION fill_array										*
*************************************************************************/

void fill_array(int arr[], int size)
{
	using namespace std;
	cout << "Enter " << size << " numbers separated by a space: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}


/************************************************************************
*				FUNCTION print_array									*
*************************************************************************/

void print_array(int arr[], int size)
{
	using namespace std;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;

}

/************************************************************************
*				FUNCTION linear_search									*
*************************************************************************/

int linear_search(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
			return i;
	}
	return -1;
}


/************************************************************************
*				FUNCTION select_sort									*
*************************************************************************/
// sorts the array by finding the smallest value and placing it in the front of the array
void select_sort(int arr[], int size) 
{
	int indexOfNextSmallest;
	for (int i = 0; i < size - 1; i++)
	{
		indexOfNextSmallest = indexOfSmallest(arr, i, size);
		swapValues(arr[i], arr[indexOfNextSmallest]);
	}
}


/************************************************************************
*				FUNCTION indexOfSmallest								*
*************************************************************************/
// returns the index of the smallest value in an array 
int indexOfSmallest(const int arr[], int startIndex, int numberUsed) 
{
	int min = arr[startIndex], indexOfMin = startIndex;
	for (int i = startIndex + 1; i < numberUsed; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			indexOfMin = i;
		}
	}
	return indexOfMin;
}


/************************************************************************
*				FUNCTION insert_sort									*
*************************************************************************/
// moves large numbers to the end of array, but stops to move smaller numbers toward the beginning.
void insert_sort(int arr[], int size) 
{
	for (int i = 0; i < (size - 1); i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swapValues(arr[i], arr[i + 1]);
			for (int j = (i - 1); j >= 0; j--)
			{
				if (arr[j] > arr[j+1])
				{
					swapValues(arr[j], arr[j+1]);
				}
			}

		}
  	}
}


/************************************************************************
*				FUNCTION bubble_sort									*
*************************************************************************/
// sorts numbers so that large numbers 'bubble up' to the end of the array.
void bubble_sort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				swapValues(arr[j], arr[j + 1]);
		}
	}
}


/************************************************************************
*				FUNCTION swapValues										*
*************************************************************************/

void swapValues(int& a, int& b) // used to swap two values
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


/************************************************************************
*				FUNCTION printValues									*
*************************************************************************/

void printValues(const int arr[], int size) // used for debugging purposes only.
{
	using namespace std;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}






/************************************************************************
*				OUTPUT													*
*************************************************************************/


//********** MENU**********
//* 1. Linear Search *
//*2. Select Sort *
//*3. Insert Sort *
//*4. Bubble Sort *
//*5. End Program *
//****************************
//Enter your choice : 1
//Enter 9 numbers separated by a space : 3 87 4 6 1 45 96 23 1
//Enter the key you want to search : 6
//The key 6 is #4 element in array
//Press any key to continue . . .
//
//********** MENU**********
//* 1. Linear Search *
//*2. Select Sort *
//*3. Insert Sort *
//*4. Bubble Sort *
//*5. End Program *
//****************************
//Enter your choice : 2
//Enter 9 numbers separated by a space : 5 8 2 6 4 9 7 12 3
//After sort, the array is :
//	2 3 4 5 6
//	7 8 9 12
//	Press any key to continue . . .
//
//	********** MENU**********
//	* 1. Linear Search *
//	*2. Select Sort *
//	*3. Insert Sort *
//	*4. Bubble Sort *
//	*5. End Program *
//	****************************
//	Enter your choice : 3
//	Enter 9 numbers separated by a space : 8 4 9 6 57 88 21 25 20
//	After sort, the array is :
//	4 6 8 9 20
//	21 25 57 88
//	Press any key to continue . . .
//
//	********** MENU**********
//	* 1. Linear Search *
//	*2. Select Sort *
//	*3. Insert Sort *
//	*4. Bubble Sort *
//	*5. End Program *
//	****************************
//	Enter your choice : 4
//	Enter 9 numbers separated by a space : 54 50 56 59 55 51 54 54 57
//	After sort, the array is :
//	50 51 54 54 54
//	55 56 57 59
//	Press any key to continue . . .
//
//	********** MENU**********
//	* 1. Linear Search *
//	*2. Select Sort *
//	*3. Insert Sort *
//	*4. Bubble Sort *
//	*5. End Program *
//	****************************
//	Enter your choice : 5
//  Thank you for using the array functions
//  Press any kety to continue . . .