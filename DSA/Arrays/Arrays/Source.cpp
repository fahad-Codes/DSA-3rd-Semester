#include<iostream>
using namespace std;

class Random
{
private:
	int arr[5];
public:
	Random()
	{
		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}
	Random(int a,int b,int c,int d, int e)
	{
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		arr[4] = e;
	}
	Random(const Random & r)
	{
		arr[0] = r.arr[0];
		arr[1] = r.arr[1];
		arr[2] = r.arr[2];
		arr[3] = r.arr[3];
		arr[4] = r.arr[4];
	}
	void Insert(int i, int v)
	{
		arr[i] = v;
	}
	void Delete(int i)
	{
		arr[i] = 0;
	}
	int Search(int v)
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			if (arr[i] == v)
			{
				return i;
			}
		}
		cout << "No Value Find";
		return 6;
	}
};

int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter " << i << " index value in array: ";
		cin >> arr[i];
	}

	Random r1(arr[0], arr[1], arr[2], arr[3], arr[4]);

	cout << arr[3] << endl;
	arr[3] = 0;
	cout << arr[3] << endl;

	r1.Delete(3);
	
	int index = 0;
	int value;

	cout << "Please enter index in which you want to enter value in array: ";
	cin >> index;
	cout << "Please enter index value in array: ";
	cin >> value;
	arr[index] = value;

	r1.Insert(index, value);

	cout << "New Value: " << arr[index] << endl;

	cout << "Enter the value you want to search: ";
	cin >> value;

	index = r1.Search(value);

	if ( index != 6)
	{
		cout << "The value is found on " << index <<" index" << endl;
	}
}