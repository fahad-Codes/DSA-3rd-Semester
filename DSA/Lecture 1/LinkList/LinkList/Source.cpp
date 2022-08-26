#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}
};

class Linkedlist
{
	Node* head;
	Node* tail;

public:
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	void insertNode(int x)
	{
		Node* temp = new Node();
		temp->data = x;

		if (head == NULL)
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
	void dislpay()
	{
		Node* temp = new Node();

		temp = head;

		while (temp != NULL)
		{
			cout << temp->data << "-->";
			temp = temp->next;
		}
	}

};
int main()
{
	Linkedlist* l1 = new Linkedlist();

	l1->insertNode(5);
	l1->insertNode(7);
	l1->insertNode(8);

	l1->dislpay();
}