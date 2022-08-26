#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int start, int end)
{
	int pivot, p, i;
	p = start;
	pivot = end;

	for (i = start; i < end; i++)
	{
		if (a[i] < a[pivot])
		{
			swap(&a[i], &a[p]);
			p++;
		}
	}
	swap(&a[pivot], &a[p]);

	return p;
}
int pivotrandom(int a[], int start, int end)
{
	int pvt, n, temp;
	n = rand();
	pvt = start + n % (end - start + 1);

	swap(&a[end], &a[pvt]);

	temp = partition(a, start, end);

	return temp;
}

int qsort(int a[], int start, int end)
{
	int pvtindex;
	if (start < end)
	{
		pvtindex = pivotrandom(a, start, end);
		qsort(a, start, pvtindex - 1);
		qsort(a, pvtindex + 1, end);
	}
	return 0;
}

int main()
{
	int n;
	int i;
	cout <<"Enter the List of Numbers To be Sorted: ";
	cin >> n;

	int * arr;
	arr = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "Enter Element No " << i + 1 << ": ";
		cin >> arr[i];
	}

	qsort(arr, 0, n - 1);
	cout << endl << "Sorted Order is";
	for (i = 0; i < n; i++)
		cout << ", " << arr[i];

}

