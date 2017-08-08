/**************************************************************************
* Program: [[DS-2]]
* Author: Akshay Pimpalkar
* Description: Enter all the elements in single Linked list
*              using while method
*
* class Node:
*       - holds the value and pointer to next node
* main method:
*       - holds value and pointer to new node
*       - while loop that get inputs from user to create new node for List
*       - for loop that prints all the values of the list
**************************************************************************/


#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

int main() {
	Node *newnode;
	int v;

	while (cout << "Enter value (0 to quit): ",
		cin >> v, v != 0) {
		newnode = new Node;
		newnode->value = v;
		newnode->next = NULL;

		if (NULL == head) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}


	}

	Node *current;
	for (current = head; current != NULL; current = current->next) {
		cout << current->value << " ";
	}



	return 0;
}
