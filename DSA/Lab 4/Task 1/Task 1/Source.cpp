#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

public:
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class Linklist
{
	Node* head;

public:
	Linklist()
	{
		head = NULL;
	}
	void addNode(int x)
	{
		Node* temp = new Node();

		temp->data = x;
		temp->next = NULL;

		if (head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNode(int no)
	{
		Node* temp1;
		Node* temp2;

		temp1 = head;
		temp2 = head;

		if (head->data == no)
		{
			head = head->next;
			temp1 = NULL;
			temp2 = NULL;
			delete temp1, temp2;
		}
		else if (head->data != no)
		{
			while (temp1->data != no)
			{
				temp1 = temp1->next;
			}
			while (temp2->next->data != no)
			{
				temp2 = temp2->next;
			}
			if (temp1 = tail)
			{
				tail = temp2;
				temp2->next = NULL;
				delete temp1;
			}
		}
	}
};