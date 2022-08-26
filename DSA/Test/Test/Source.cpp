#include<iostream>
using namespace std;

class Stock
{
private:

	int productid;
	char productname[30];
	int productquantity;
	float price;


public:


	Stock()
	{
		productid = 0;
		productname[30] = ' ';
		productquantity = 0;
		price = 0.0;
	}

	Stock(int pd, char pn, int pq, float p)
	{
		productid = pd;
		productname[30] = pn;
		productquantity = pq;
		price = p;
	}

	void showproduct()
	{
		cout << "Product ID:" << productid << endl;
		cout << "Product Name:" << productname << endl;
		cout << "Product Quantity:" << productquantity << endl;
		cout << "Price:" << price << endl;
	}

	int getproductid()
	{
		return productid;
	}

	char getproductname()
	{
		return productname[30];
	}
	int getproductquantity()
	{
		return productquantity;
	}
	float getprice()
	{
		return price;
	}

	void setproductid(int productid)
	{
		this->productid = productid;
	}

	void setproductname(char productname)
	{
		this->productid = productid;
	}

	void setproductquantity(int productquantity)
	{
		this->productquantity = productquantity;
	}
	void setprice(float price)
	{
		this->price = price;
	}

	~Stock()
	{

	}


	void Addproduct()
	{
		productquantity = productquantity + 1;
	}

	void Sales()
	{
		productquantity = productquantity - 1;
	}

	void searchproduct(Stock s[])
	{

		int pd;


		cout << "Enter the product id:" << endl;
		cin >> pd;

		if (pd == productid)
		{
			cout << "Product Found:" << endl;
		}

		else
		{

			cout << "NOT Found" << endl;
		}

	}

	void quantityavailable(Stock s[])
	{

		int pd;
		cout << "Enter the product Id:" << endl;
		cin >> pd;


		if (pd == productid)
		{
			cout << "Product Available in Stock:" << productquantity << endl;
		}
		else
		{
			cout << "NOT Available" << endl;
		}

	}

};



int main()
{

	Stock* St = new Stock[5];
	int choices;

	cout << "		Main Menu " << endl;
	cout << " 1_Add product  " << endl;
	cout << " 2_Show product  " << endl;
	cout << " 3_Search product  " << endl;
	cout << " 4_sale product  " << endl;
	cout << " 5_Quantity of product  " << endl;

	cin >> choices;

	switch (choices)
	{

	case 1: St[0].Addproduct();
		break;
	case 2: St[0].showproduct();
		break;
	case 3:St[0].searchproduct(St);
		break;
	case 4:St[0].Sales();
		break;
	case 5: St[0].quantityavailable(St);
		break;
	}

	return 0;

}