#include<iostream>
using namespace std;

class Queue
{
private:
	int arr[10];
	int front;
	int rare;
	int capacity;
public:
	Queue()
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
		front = 0;
		rare = 0;
		capacity = 10;
	}
	bool isFull()
	{
		if (rare == capacity)
			return true;
		return false;
	}
	bool isEmpty()
	{
		if (front == capacity)
			return true;
		return false;
	}
	void Enqueue(int a)
	{
		if (!isFull())
		{
			if (rare == 0)
			{
				arr[rare] = a;
				rare++;
			}
			else
			{
				arr[rare] = a;
				rare++;
			}

		}
		else
		{
			cout << "The  queue is already full." << endl;
		}
	}
	int Dequeue()
	{
		int x;

		if (!isEmpty())
		{
			if (front == 0)
			{
				front++;
				x = arr[0];
			}
			else
			{
				x = arr[front];
				front++;
			}
			return x;
		}
		else
		{
			cout << "The  queue is empty." << endl;
		}
	}
	void display()
	{
		int x;
		for (int i = 0; i < capacity; i++)
		{
			x = Dequeue();
			cout << x << endl;
		}
	}
};
int main()
{
	Queue* q1 = new Queue();

	int x;
	cout << "Please enter 10 values in queue:";
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		q1->Enqueue(x);
	}

	q1->display();
}