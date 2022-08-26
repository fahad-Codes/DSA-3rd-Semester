#include<iostream>
using namespace std;

class NewLogic
{
private:
	int arr[6];
	int secretNumber;
	friend void find_secret();
public:
	NewLogic()
	{
		arr[0] = 4;
		arr[1] = 5;
		arr[2] = 16;
		arr[3] = 10;
		arr[4] = 20;
		arr[5] = 3;
		secretNumber = 4;
	}
};

void find_secret()
{
	NewLogic n;
	for (int i = 0; i < 6; i++)
	{
		if (n.secretNumber == n.arr[i])
		{
			
			cout << "The secret number is found.";
			return;
		}

	}
	cout << "The secret number is not found.";
	return;
}
int main()
{
	find_secret();
}