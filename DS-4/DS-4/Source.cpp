/*****************************************************************************
* Program: [[DS-4]]
* Author: Akshay Pimpalkar
* Description:
* class Node:
*       - holds the value and pointer to next and previous node
*       - constructor which initializes value, next and previous node
* class DoubleLinkedList:
*       - holds pointer to head and tail
*       - constructor to initialize head and tail pointers
*       - destructor for deleting all the list nodes
*       - 'add' method for adding nodes to the list at the end
*       - print method to print all the nodes of the list
*       - printRev method for print the list in the reverse order
*       - printBackToFront method is a wrapper method which wraps
*         the the printRev method and calls it using data abstraction
* main method:
*       - Creates DoubleLinkedList's object and then calling add method
*         several times and then calling print method followed by printToBack
*         method
* Revision History:
*       25-March-2017 : [[DS-3]]
*       25-March-2017 : [[DS-3-A]] Added destructor
*       25-March-2017 : [[DS-3-B]] Added methods printRev and printBackToFront
*******************************************************************************/

#include <iostream>

using namespace std;


class Node {
public:
	Node *prev;
	int value;
	Node *next;

	Node(int v) {
		prev = NULL;
		value = v;
		next = NULL;
	}
};

class DoubleLinkedList {
	Node *head;
	Node *tail;

public:
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void add(int v) {
		Node *newnode = new Node(v);

		if (NULL == head) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
	}

	void print() {
		for (Node *current = head; current; current = current->next)
			cout << current->value << " ";
	}


	void printBackToFront() {
		for (Node *current = tail; current; current = current->prev)
			cout << current->value << " ";

	}

	bool deleteNode(int v) {
		for (Node *current = head; current; current = current->next) {
			if (current->value == v) {
				if (head == tail) {
					delete current;
					head = NULL;
					tail = NULL;
					cout << "\ncurrent is deleted with type 2" << endl;
					return true;
				}
				if (current == head) {
					head = head->next;
					delete current;
					head->prev = NULL;
					cout << "\ncurrent is deleted with type 3" << endl;
					return true;
				}
				if (current == tail) {
					tail = current->prev;
					delete current;
					tail->next = NULL;
					cout << "\ncurrent is deleted with type 4" << endl;
					return true;
				}
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				cout << "\ncurrent is deleted with type 5" << endl;
				return true;
			}
		}

		return false;
	}


	~DoubleLinkedList() {
		Node *temp = head;
		while (head) {
			head = head->next;
			delete temp;
			temp = head;
		}
		cout << "\ndestructor is called!" << endl;
	}

	bool insertAfter(int newV, int v)
	{
		for (Node *current = head; current; current = current->next) {
			if (current->value == v)
			{
				if (current->next == NULL)
				{
					current->next = new Node(newV);
					tail = current->next;

				}
				else
				{
					Node *newnode = new Node(newV);
					newnode->next = current->next;
					newnode->prev = current;
					current->next->prev = newnode->prev->next = newnode;

				}
			}
		}
		return false;
	}

	bool insertBefore(int newV, int v) {
		for (Node *current = head; current; current = current->next) {
			if (current->value == v) {
				if (current == head) {
					current->prev = new Node(newV);
					head = current->prev;
					head->next = current;
					return true;
				}
				else {
					Node *newnode = new Node(newV);
					newnode->next = current;
					newnode->prev = current->prev;
					current->prev->next = current->prev = newnode;
					return true;
				}

			}
		}
		return false;
	}

	bool addToBack(int newV) {

		tail->next = new Node(newV);
		tail->next->prev = tail;
		tail = tail->next;
		cout << "\n" << newV << " is added to back" << endl;
		return true;


	}

	bool addToFront(int newV) {
		head->prev = new Node(newV);
		head->prev->next = head;
		head = head->prev;

		cout << "\n" << newV << " is added to front" << endl;
		return true;
	}

};

int main()
{
	DoubleLinkedList m1;
	m1.add(4);
	m1.add(6);
	m1.add(8);
	m1.add(9);
	m1.add(5);

	cout << "\nForward printing is: ";
	m1.print();
	cout << "\n";
	cout << "\nReverse printing is: ";
	m1.printBackToFront();

	cout << m1.deleteNode(8);
	cout << "\nForward printing is: ";
	m1.print();

	m1.insertAfter(21, 6);
	cout << "\n";
	m1.print();

	m1.insertBefore(15, 21);
	cout << "\n";
	m1.print();

	m1.addToBack(45);
	cout << "\n";
	m1.print();

	m1.addToFront(67);
	cout << "\n";
	m1.print();
}
