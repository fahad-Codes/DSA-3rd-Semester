#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

class LinkedList
{
	Node* head = NULL;

public:
	void insertAtHead(int value)
	{
		Node* node = new Node;
		node->value = value;

		if (head == NULL)
		{
			node->next = NULL;
		}
		else
		{
			node->next = head;
		}
		head = node;
	}

	void displayList()
	{
		Node* flag = head;
		while (flag != NULL)
		{
			cout << "  " << flag->value;
			flag = flag->next;
		}
		cout << endl;
	}

	void deleteall() {
		Node* temp;
		while (head!=nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void reverse()
	{
		Node* tempNode = NULL;
		Node* prevNode = NULL;
		Node* currentNode = head;

		while (currentNode != NULL)
		{
			tempNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = tempNode;
		}
		head = prevNode;
	}

	Node* copyList(LinkedList L) 
	{

		Node* current = L.head;

		Node* copy = new Node;
		copy->value = current->value;
		copy->next = NULL;

		Node* const head1 = copy;

		current = current->next;

		while (current != NULL) {
			copy = copy->next = new Node;

			copy->value = current->value;

			copy->next = NULL;

			current = current->next;
		}

		head = head1;
		return head;
	}

	string compare(LinkedList l1,LinkedList l2)
	{
		Node *list1 = l1.head;
		Node *list2 = l2.head;
		while (list1 && list2 && list1->value == list2->value)
		{
			list1 = list1->next;
			list2 = list2->next;
		}

		if (list1 && !list2) return "Not Equal";

		return "Equal";
	}
};

int main()
{
	LinkedList linkedList;

	linkedList.insertAtHead(3);
	linkedList.insertAtHead(4);
	linkedList.insertAtHead(6);
	linkedList.insertAtHead(7);
	linkedList.insertAtHead(8);

	cout << "LinkedList: ";

	linkedList.displayList();

	cout << "Reverse LinkedList: ";
	linkedList.reverse();
	linkedList.displayList();

	cout << "Copy LinkedList: ";
	LinkedList copy;
	copy.copyList(linkedList);
	copy.displayList();

	cout << "Compare LinkedList: ";
	cout << linkedList.compare(linkedList, copy);

	cout << endl << "Delete LinkedList: ";
	linkedList.deleteall();
	linkedList.displayList();
	return 0;
}