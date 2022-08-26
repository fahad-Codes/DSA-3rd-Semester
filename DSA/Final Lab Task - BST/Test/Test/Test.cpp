#include <iostream>
using namespace std;
class Node
{
public:
	float data;
	Node* next;
	Node()
	{
		data = 0.0;
		next = NULL;
	}
};
class LinkList
{
private:
	Node* head;
	Node* tail;
public:
	LinkList()
	{
		head = NULL;
		tail = NULL;
	}
	void Add(Node& N)
	{
		Node* temp = &N;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else if (head->data >= temp->data)
		{
			temp->next = head;
			head = temp;
			tail->next = head;
		}
		else
		{
			Node* temp1 = head;
			Node* temp2 = temp1;
			while (temp->data > temp1->data)
			{
				if (temp1 == tail)
				{
					break;
				}
				else
				{
					temp2 = temp1;
					temp1 = temp1->next;
				}
			}
			if (temp1 == tail)
			{
				temp1->next = temp;
				tail = temp;
				tail->next = head;
			}
			else
			{
				temp2->next = temp;
				temp->next = temp1;
			}
		}
	}
	void Display()
	{
		cout << "\n\nD\n\n";
		Node* temp = head;
		int i = 1;
		bool c = true;
		if (head == NULL)
		{
			cout << "\n\nLinkedList is Empty";
		}
		else
		{
			while (c == true)
			{
				cout << "\n\nData of Node " << i << " is: " << temp->data;
				i++;
				temp = temp->next;
				if (temp == tail)
				{
					cout << "\n\nData of Node " << i << " is: " << temp->data;
					c = false;
				}
			}
		}
	}
};
int main()
{
	Node N;
	LinkList P;
	LinkList* L = &P;
	int choice;
	bool c = true;
	do
	{
		cout << "\n\nEnter Choice"
			<< "\n\t1. Add Node"
			<< "\n\t2. Display"
			<< "\n\t3. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "\n\nEnter Data: ";
			cin >> N.data;
			L->Add(N);
			break;
		}
		case 2:
		{
			L->Display();
			break;
		}
		case 3:
		{
			c = false;
			break;
		}
		default:
		{
			cout << "\n\nInvalid choice\n";
		}
		}
	} while (c == true);
	cout << "\n\n";
}