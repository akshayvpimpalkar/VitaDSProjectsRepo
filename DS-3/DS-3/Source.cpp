/*****************************************************************************
* Program: [[DS-3]]
* Author: Akshay Pimpalkar
* Description: Add elements to Single LinkedList and print it front to back
back to front
* class Node:
*       - holds the value and pointer to next node
*       - constructor which initializes value and next node
* class SingleLinkedList:
*       - holds pointer to head and tail
*       - constructor to initialize head and tail pointers
*       - destructor for deleting all the list nodes
*       - 'add' method for adding nodes to the list at the end
*       - print method to print all the nodes of the list
*       - printRev method for print the list in the reverse order
*       - printBackToFront method is a wrapper method which wraps
*         the the printRev method and calls it using data abstraction
* main method:
*       - Creates SingleLinkedList's object and then calling add method
*         several times and then calling print method followed by printToBack
*         method
* Revision History:
*       25-March-2017 : [[DS-3]]
*       25-March-2017 : [[DS-3-A]] Added destructor
*       25-March-2017 : [[DS-3-B]] Added methods printRev and printBackToFront
*******************************************************************************/

#include <iostream>

using namespace std;

/*
* class Node that holds value and pointer to next node
*/
class Node {
public:
	int value;
	Node *next;

	Node(int v) {
		value = v;
		next = NULL;
	}
};

/*
* class SingleLinkedList that holds pointer to head and tail
*/
class SingleLinkedList {
	Node *head;
	Node *tail;

public:
	/*
	*constructor to initialize head and tail pointers
	*/
	SingleLinkedList() {
		head = NULL;
		tail = NULL;
	}

	/*
	* destructor for deleting all the list nodes
	*/
	~SingleLinkedList() {
		Node *temp = head;
		while (head) {
			head = head->next;
			delete temp;
			temp = head;
		}
		cout << "\ndestructor is called!" << endl;
	}

	/*
	* add method for adding nodes to the list at the end
	*/
	void add(int v) {
		Node *newnode = new Node(v);

		if (NULL == head) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
	}
	/*
	*print method to print all the nodes of the list
	*/
	void print() {
		for (Node *current = head; current; current = current->next)
			cout << current->value << " ";
	}

	/*
	*printRev method for print the list in the reverse order
	*/
	void printRev(Node *n) {
		if (!n) {
			return;
		}
		printRev(n->next);
		cout << n->value << " ";
	}

	/*
	* printBackToFront method is a wrapper method which wraps
	* the the printRev method and calls it using data abstraction.
	*/
	void printBackToFront() {
		printRev(this->head);
	}



};

/*
* main method that creates SingleLinkedList's object and then calling add method
* several times and then calling print method followed by printToBack
* method
*/
int main()
{
	SingleLinkedList m1;
	m1.add(4);
	m1.add(6);
	m1.add(8);
	m1.add(9);
	m1.add(5);

	cout << "Forward printing is: ";
	m1.print();
	cout << "\n";
	cout << "Reverse printing is: ";
	m1.printBackToFront();
}
