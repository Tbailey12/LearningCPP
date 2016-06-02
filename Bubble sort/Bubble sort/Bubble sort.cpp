#include "stdafx.h"
#include <iostream>
#include <utility>

using namespace std;

void printArray(int array[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << ",";
	}
	cout << "\n";
}

void sortArray(int array[],int size) 
{
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1; ++j) {
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}

}


int main()
{
	int theArray[]{ 7,3,2,5,9,8,0,1,3,4,6,121,3,5,76,6,4 };
	//sizeof returns size of array in bytes
	int size = sizeof(theArray) / (sizeof(int));				
	cout << "Before: ";
	printArray(theArray,size);
	sortArray(theArray,size);
	cout << "After: ";
	printArray(theArray,size);
    return 0;
}