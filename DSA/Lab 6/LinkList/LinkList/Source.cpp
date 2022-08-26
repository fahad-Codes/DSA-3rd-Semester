#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class Linklist
{
public:
	Node* head;

	Linklist()
	{
		head = NULL;
	}

	void insert(int data)
	{
		Node* temp = new Node(data);
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head->next;
			head->next = temp;
		}
		cout << "The node with data " << data << " is added." <<endl;
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

	int size() 
	{

		Node* temp = head;

		int count = 0;

		while (temp) 
		{

			++count;

			temp = temp->next;

		}

		return count;

	}

	Node* SortedList(Node* lst1, Node* lst2)
	{
		Node* result = NULL;

		if (lst1 == NULL)
			return (lst2);
		else if (lst2 == NULL)
			return (lst1);

		if (lst1->data <= lst2->data) {
			result = lst1;
			result->next = SortedList(lst1->next, lst2);
		}
		else {
			result = lst2;
			result->next = SortedList(lst1, lst2->next);
		}
		return result;
	}

	Node merge_sorted(Node head1, Node head2) 
	{

		if (head1 == nullptr) {
			return head2;
		}
		else if (head2 == nullptr) {
			return head1;
		}


		Node mergedHead = nullptr;
		if (head1->data <= head2->data) {
			mergedHead = head1;
			head1 = head1->next;
		}
		else {
			mergedHead = head2;
			head2 = head2->next;
		}

		Node mergedTail = mergedHead;

		while (head1 != nullptr && head2 != nullptr) {
			Node temp = nullptr;
			if (head1->data <= head2->data) {
				temp = head1;
				head1 = head1->next;
			}
			else {
				temp = head2;
				head2 = head2->next;
			}

			mergedTail->next = temp;
			mergedTail = temp;
		}

		if (head1 != nullptr) {
			mergedTail->next = head1;
		}
		else if (head2 != nullptr) {
			mergedTail->next = head2;
		}

		return mergedHead;
	}

	bool isPresent(int data) 
	{

		Node* temp = head;

		while (temp) 
		{

			if (temp->data == data) 
			{

			return true;

			}

			temp = temp->next;

		}

		return false;

	}

	void findnAdd(int x)
	{
		if (isPresent(x))
		{
			cout << "It's present, Hance deleting it";
			deleteNode(x);
		}
		else
		{
			cout << "It's not present, hence adding it.";
			insert(x);
		}
	}

	void display()
	{
		Node* temp = head;
		while (head != NULL)
		{
			cout << head->data <<"--->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
};

int main()
{
	cout << "Creating a singly linked list" << endl;
	Linklist* ll = new Linklist();
	ll->insert(4);
	ll->insert(2);
	ll->insert(7);
	ll->insert(3);
	ll->deleteNode(2);
	ll->display();

}