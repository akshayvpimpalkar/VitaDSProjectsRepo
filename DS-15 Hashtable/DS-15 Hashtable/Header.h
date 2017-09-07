#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
using namespace std;

template <class type, class type2>
class HashEntry {
public:
	HashEntry<type, type2> *next;
	type key;
	type2 value;

	HashEntry(type k, type2 v) {
		key = k;
		value = v;
		next = NULL;
	}
};

template <class type, class type2>
class HashTable {
	HashEntry <type, type2> **table;
	int size;

public:
	HashTable(int s) {
		size = s;
		table = new HashEntry<type, type2>*[size];

		for (int i = 0; i < size; i++) {
			table[i] = NULL;
		}
	}

	bool put(type k, type2 v) {
		int offset = k % size;

		/*hash<type> hasher;
		int offset = hasher(type) % size;*/
		HashEntry <type, type2> *current;
		for (current = table[offset]; current; current = current->next) {
			if (current->key == k) {
				return false;
			}
		}

		current = new HashEntry <type, type2>(k, v);
		current->next = table[offset];
		table[offset] = current;
		cout << v << " added" <<endl;
		return true;
	}

	bool get(type k, type2 &out) {
		int offset = k % size;

		/*hash<type> hasher;
		int offset = hasher(type) % size;*/
		HashEntry <type, type2> *current;
		for (current = table[offset]; current; current = current->next) {
			if (current->key == k) {
				out = current->value;
				return true;
			}
		}
		return false;

	}
};

