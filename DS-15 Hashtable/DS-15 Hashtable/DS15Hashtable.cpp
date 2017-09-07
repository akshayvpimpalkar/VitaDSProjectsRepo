// DS15Hashtable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Header.h"
#include <string>
using namespace std;

int main()
{
	
	HashTable <char, string> h1(5);

	h1.put('A', "Akshay");
	h1.put('B', "Keshav");
	h1.put('C', "Priyanka");
	h1.put('D', "Aditya");

	cout << h1.put('A', "Saurabh"); // this prints 0 because i entered key(here 'A') which is already present 
									//i haven't written any code in Hashtable to create linked list 
									//for key collision condition

	cout << endl;

	bool b;
	string ref;
	char c;
	while (cout << "\nEnter a character to get the value or '.' to quit: ", cin >> c, c!='.') {
		b = h1.get(c, ref);

		if (b) {
			cout << ref << " is found" << endl;
		}
		else {
			cout <<" Invalid key entered!" << endl;
		}
	}
    return 0;
}

