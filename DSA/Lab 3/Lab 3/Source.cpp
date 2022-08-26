#include<iostream>
using namespace std;



int main()
{
	int array[5];
	int size = 5;
	for (int i = 0; i < 5; i++)
	{
		cout << "Please Enter the array value: ";
		cin >> array[i];
	}

	int i, j, imin;

	for (i = 0; i < size - 1; i++) {
		imin = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[imin])
				imin = j;

		int temp = array[i];
		array[i] = array[imin];
		array[imin] = temp;
	}

	cout << "The Sorted Array Values: ";

	for (int i = 0; i < 5; i++)
	{
		cout << array[i]<<" ";
		
	}




}