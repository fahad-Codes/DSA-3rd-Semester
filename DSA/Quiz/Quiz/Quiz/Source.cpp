#include<iostream>
#include<string>
using namespace std;

class Train
{
private:
	int TrainNumber;
	string TrainName;
	string Source;
	string Destination;
	string Date;
	int Capacity;

public:
	Train()
	{
		TrainNumber = 0;
		TrainName = " ";
		Source = " ";
		Destination = " ";
		Date = " ";
		Capacity = 0;
	}
	Train(int tno, string tna, string s, string de, string da, int c)
	{
		TrainNumber = tno;
		TrainName = tna;
		Source = s;
		Destination = de;
		Date = da;
		Capacity = c;
	}
	void display()
	{
		cout << "The number of the Train is " << TrainNumber << endl;
		cout << "The Name of the Train is " << TrainName << endl;
		cout << "The source of the Train is " << Source << endl;
		cout << "The destination of the Train is " << Destination << endl;
		cout << "The Date of the Train arival is " << Date << endl;
		cout << "The capacity of the Train is " << Capacity << endl;
	}
};
int main()
{
	Train t1(1, "Zeta", "Berlin", "Mosscow", "02-09-2022", 200);
	t1.display();
}