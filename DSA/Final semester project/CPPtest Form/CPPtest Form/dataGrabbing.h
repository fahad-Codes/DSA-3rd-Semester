#pragma once
#include<string>
#include<iostream>
using namespace std;

class GrabData
{
public:
	string data;
	GrabData(string a)
	{
		data = a;
		cout << a;
	}
	string returndata()
	{
		return data;
	}
};