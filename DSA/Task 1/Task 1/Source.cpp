#include<iostream>
#include<string>
using namespace std;
class Hotel
{
private:
	int roomNo;
	float size;
	char Roomtype;
	string BookingName;
	friend void havingFun();
public:
	Hotel()
	{
		roomNo = 0;
		size = 0.0;
		Roomtype = ' ';
		BookingName = " ";
		cout << "Default Constructor" << endl;
	}
	Hotel(int a, float b, char c, string d)
	{
		roomNo = a;
		size = b;
		Roomtype = c;
		BookingName = d;
		cout << "Perameterized Constructor" << endl;
	}
	Hotel(const Hotel& h)
	{		
		roomNo = h.roomNo;
		size = h.size;
		Roomtype = h.Roomtype;
		BookingName = h.BookingName;
		cout << "Copy Constructor" << endl;
	}
	void setRoomNo(int a)
	{
		roomNo = a;
		cout << "Set Room No";
	}
	int getRoomNo()
	{
		return roomNo;
		cout << "Get Room No";
	}
	void setSize(float b)
	{
		size = b;
		cout << "Set Size";
	}
	float getSize()
	{
		return size;
		cout << "Get Size";
	}
	void setRoomType(char c)
	{
		Roomtype = c;
		cout << "Set Room Type";
	}
	char getRoomType()
	{
		return Roomtype;
		cout << "Get Room Type";
	}
	void setName(string d)
	{
		BookingName = d;
		cout << "Set Name";
	}
	string getName()
	{
		return BookingName;
		cout << "Get Name";
	}
	void havingFun()
	{

		cout << "Having Fun 1.1" << endl;
	}
	~Hotel()
	{		
		cout << "Destructor";
	}
};
class Temp:public Hotel
{
private:
	int eg;	
public:
	void havingFun()
	{
		
		cout << "Having Fun 1.2" << endl;
	}

};
void havingFun()
{
	Hotel h(2,50.1,'N',"Hamza");
	cout << h.BookingName << endl;
	cout << "Having Fun 2" << endl;
}
int main()
{
	Hotel h1;
	Hotel h2(1, 50.5, 'L', "Muhammad Fahad");
	Hotel h3 = h2;
	Temp t;
	h1.havingFun();
	t.havingFun();
	havingFun();
}