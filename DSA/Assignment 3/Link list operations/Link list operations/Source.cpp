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

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class Linklist
{
	Node* head;
	Node* tail;

public:

	Linklist()
	{
		head = NULL;
		tail = NULL;
	}

	void insert(int data)
	{
		Node* temp = new Node(data);
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

	void deleteNode(int data)
	{
		if (head == NULL)
		{
			cout << "currently there is no node to delete" << endl;
			return;
		}
		else if (data == head->data)
		{
			if (head->next == NULL)
			{
				head = NULL;
			}
			else
			{
				head = head->next;
			}
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->data == data)
			{
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
	}

	void reverseLL()
	{
		if (head == NULL)
		{
			return;
		}
		else if (head->next == NULL)
		{
			return;
		}
		else
		{
			Node* temp = new Node();
			Node* temp1 = new Node();

			temp = head;
			head = tail;
			tail = temp;

			temp1 = tail;
			temp = head;

			while (tail->next != head)
			{
				while (temp1->next->next != head)
				{
					temp1 = temp1->next;
				}
				temp->next = temp1->next;
				temp = temp->next;
				temp1->next = head;
				temp1 = tail;
			}

			temp->next = tail;
			tail->next = NULL;
		}
	}

	Linklist operator = (Linklist const& l1)
	{
		Node* temp = new Node();

		temp = l1.head;

		while (temp!=NULL)
		{
			insert(temp->data);
			temp = temp->next;
		}
	}

	void deleteLL()
	{
		while (head != NULL)
		{
			deleteNode(head->data);
		}
	}

	bool compare(Linklist const & l1)
	{
		Node* temp = new Node();
		Node* temp1 = new Node();

		temp = head;
		temp1 = l1.head;

		while (temp != NULL && temp1 != NULL)
		{
			if (temp1->data == temp->data)
			{
				temp = temp->next;
				temp1 = temp1->next;
			}
			else
			{
				return false;
			}
		}
		
		if (temp == NULL && temp1 == NULL)
		{
			return true;
		}
			
		else
			return false;
	}

	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "--->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main()
{
	cout << "	Creating a singly linklist" << endl << endl;

	Linklist* ll = new Linklist();

	ll->insert(3);
	ll->insert(4);
	ll->insert(6);
	ll->insert(7);
	ll->insert(8);

	cout << endl << "The current linklist:  ";	
	ll->display();

	cout << endl << "The reversed linklist:  ";
	ll->reverseLL();
	ll->display();


	cout << endl << "Copying linklist into another linklist:  ";
	Linklist* l1 = new Linklist();
	l1 = ll;
	l1->display();

	cout << endl << "Comparing 2nd with above linklist:  ";
	Linklist* l2 = new Linklist();

	l2->insert(8);
	l2->insert(7);
	l2->insert(6);
	l2->insert(4);
	l2->insert(3);
	l2->insert(9);

	cout << endl << "2nd linklist:  ";  
	l2->display();

	if (l1->compare(*l2))
	{
		cout << "They are similar nigga!" << endl;
	}
	else
	{
		cout << "They are not similar!" << endl;
	}

	cout << endl << "Deleted the 2nd linklist: ";
	l2->deleteLL();
	l2->display();
}