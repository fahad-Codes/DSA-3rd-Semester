#include <iostream>
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
	cout << "The entered array is ";
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}		
	
	return 0;
}