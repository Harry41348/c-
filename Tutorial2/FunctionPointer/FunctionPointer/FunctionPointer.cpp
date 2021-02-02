// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
using namespace std;

void selectionSort(int[], const int, bool(*) (int, int));
void swap(int * const, int * const);
bool ascending(int, int);
bool descending(int, int);


int main()
{
	const int arraySize = 10;
	int a[arraySize] = { 10, 7, 3, 68, 9, 345, 4, 3, 6, 89 };
	int order; //1 ascending, 2 descending
	cout << "Enter 1 for ascending, 2 for descending" << endl;
	cin >> order;

	cout << "original order: " << endl;
	//ouput original array order
	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << a[i];
	}

	if (order == 1) {
		selectionSort(a, arraySize, ascending);
	}
	else {
		selectionSort(a, arraySize, descending);
	}
	cout << endl << "new order: " << endl;
	//ouput new array order
	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << a[i];
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

void selectionSort(int work[], const int size, bool(*compare)(int, int))
{
	int smalledOrLargest;

	for (int i = 0; i < size - 1; i++)
	{
		smalledOrLargest = i; //first index
		//loop to find index of smallest (or largest) element
		for (int index = i + 1; index < size; index++)
		{
			if (!(*compare)(work[smalledOrLargest], work[index]))
				smalledOrLargest = index;
			swap(&work[smalledOrLargest], &work[i]);
			smalledOrLargest = i;
		}

	}
}

//swap the values at memory locations to which.
//element1Ptr and element2Ptr point.
void swap(int * const element1Ptr, int * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

bool ascending(int a, int b)
{
	return a < b;//return true if b is greater than a
}

bool descending(int a, int b)
{
	return a > b; //return true if a is greater than b
}