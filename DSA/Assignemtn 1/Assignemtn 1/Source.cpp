#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Stock
{
private:
	int productID;
	string productName;
	int productQuantity;
	float price;
public:
	Stock()
	{
		productID = 0;
		productName = " ";
		productQuantity = 0;
		price = 0.0;
	}
	Stock(int pi, string pn, int pq, float pr)
	{
		productID = pi;
		productName = pn;
		productQuantity = pq;
		price = pr;
	}
	int getProductID()
	{
		return productID;
	}
	void setProductID(int pd)
	{
		productID = pd;
	}
	string getProductName()
	{
		return productName;
	}
	void setProductName(char pn)
	{
		productName = pn;
	}
	int getProductQuantity()
	{
		return productQuantity;
	}
	void setProductQuantity(int pq)
	{
		productQuantity = pq;
	}
	float getPrice()
	{
		return price;
	}
	void setprice(float p)
	{
		price = p;
	}
	void addProduct(int pi, string pn, int pq, float pr)
	{
		productID = pi;
		productName = pn;
		productQuantity = pq;
		price = pr;
		cout << "Product Added!" << endl;
		_getch();
		return;
	}
	void showProduct(Stock s[])
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "The Product ID is " << s[i].productID << endl;
			cout << "The product Name is " << s[i].productName << endl;
			cout << "The Quantity of the product is " << s[i].productQuantity << endl;
			cout << "The price of the product is " << s[i].price << endl;
		}
		
		_getch();
		return;
	}
	void searchProduct(Stock s[])
	{
		int option;
		int PID;
		string PName;
		cout << "Press 1 to search by Product ID or press 2 to search by name: ";
		cin >> option;
		
		if (option == 1)
		{
			cout << "Please enter the product ID: ";
			cin >> PID;
			for (int i = 0; i < 5; i++)
			{
				if (s[i].productID == PID)
				{
					cout << "Product Found." << endl;
					cout << "The Product ID is " << s[i].productID << endl;
					cout << "The product Name is " << s[i].productName << endl;
					cout << "The Quantity of the product is " << s[i].productQuantity << endl;
					cout << "The price of the product is " << s[i].price << endl;
					_getch();
					return;
				}
			}
			cout << "Product not found!" << endl;
			_getch();
			return;
		}
		else if (option==2)
		{
			cout << "Please enter the product name: ";
			getline(cin, PName);
			getline(cin, PName);
			for (int i = 0; i < 5; i++)
			{
				if (s[i].productName == PName)
				{
					cout << "Product Found." << endl;
					cout << "The Product ID is " << s[i].productID << endl;
					cout << "The product Name is " << s[i].productName << endl;
					cout << "The Quantity of the product is " << s[i].productQuantity << endl;
					cout << "The price of the product is " << s[i].price << endl;
					_getch();
					return;
				}
			}
			cout << "Product not found!" << endl;
			_getch();
			return;
		}
		else
		{
			cout << "Wrong Option Selected!" << endl;
			_getch();
			return;
		}
	}
	void sales(Stock s[])
	{
		int PID;
		cout << "Please enter the product ID you want to purchase: ";
		cin >> PID;
		for (int i = 0; i < 5; i++)
		{
			if (s[i].productID == PID)
			{
				cout << "Product Found." << endl;
				cout << "Placing Order.....!" << endl;
				if (s[i].productQuantity > 0)
				{
					cout << "Item Purchased!" << endl;
					s[i].productQuantity--;
					_getch();
					return;
				}
				else
				{
					cout << "Order can't be placed due to zero stock.....!" << endl;
					_getch();
					return;
				}
			}						
		}
		cout << "Product not found!" << endl;
		_getch();
		return;
	}
	void quatityAvailable(Stock s[])
	{
		int PID;
		cout << "Please enter the product ID you want to check: ";
		cin >> PID;
		for (int i = 0; i < 5; i++)
		{
			if (s[i].productID == PID)
			{
				cout << "Product Found." << endl;
				cout << "Checking Quatity.....!" << endl;
				if (s[i].productQuantity > 0)
				{
					cout << "The available quatity of the product is " << s[i].productQuantity << endl;
					_getch();
					return;
				}
				else
				{
					cout << "Product not available due to zero stock.....!" << endl;
					_getch();
					return;
				}
			}
			
		}
		cout << "Product not found!" << endl;
		_getch();
		return;
	}
	~Stock()
	{
	}
};
int main()
{
	int productID;
	string productName;
	int productQuantity;
	float price;
	int cpc = 0;

	Stock* st = new Stock[5];


	for (int i = 0; i < 5; i++)
	{
		
		cout << "Enter Product's ID: ";
		cin >> productID;
		cout << "Enter Product's Name: ";
		getline(cin, productName);
		getline(cin, productName);
		cout << "Enter Product's Quantity: ";
		cin >> productQuantity;
		cout << "Enter Product's price: ";
		cin >> price;

		st[i].addProduct(productID, productName, productQuantity, price);
		cpc++;
	}

	int choice = 0;
	while (choice != 6)		
	{

		system("cls");
		cout << endl << "\t\t\t <---------------------Stock Management---------------------> ";
		cout << endl << "\t\t\t\t		<--- MAIN MENU --->";

		cout << endl << endl << endl << "\t\t\t1) Add Product";
		cout << endl << "\t\t\t2) Show Products";
		cout << endl << "\t\t\t3) Search Product";
		cout << endl << "\t\t\t4) Sales";
		cout << endl << "\t\t\t5) Quantity Available";
		cout << endl << "\t\t\t6) Exit";
		cout << endl << "\n\t\t\tEnter Your Choice: ";
		cin >> choice;

		switch (choice)
		{

		case 1: {
			cout << "Enter Product's ID: ";
			cin >> productID;
			cout << "Enter Product's Name: ";
			getline(cin, productName);
			getline(cin, productName);
			cout << "Enter Product's Quantity: ";
			cin >> productQuantity;
			cout << "Enter Product's price: ";
			cin >> price;	st[cpc].addProduct(productID, productName, productQuantity, price);
			cpc++;
		}
				break;

			case 2: st[0].showProduct(st);
				break;

			case 3: st[0].searchProduct(st);
				break;

			case 4:	st[0].sales(st);
				break;
			case 5: st[0].quatityAvailable(st);
				break;
			case 6: break;
			default:
			{

				cout << endl << "\t\t\tPlease enter a Valid Choice between 1-5:";
				cin >> choice;
			}

		}

	}
}