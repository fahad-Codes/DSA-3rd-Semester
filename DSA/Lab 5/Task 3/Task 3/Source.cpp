#include<iostream>
using namespace std;

int main()
{
	int* A, length;

	cout << "Please enter size of array: ";
	cin >> length;

	A = new int[length];


	for (int i = 0; i < length; i++)
	{
		cout << "Please enter array value: " << endl;
		cin >> A[i];
	}
	
	for (int i = 0; i < length - 1; i++) {
		int imin = i;
		for (int j = i + 1; j < length; j++)
			if (A[j] < A[imin])
				imin = j;

		int temp = A[i];
		A[i] = A[imin];
		A[imin] = temp;
	}

	cout << "The second largest value is " << A[length - 2];

	
}