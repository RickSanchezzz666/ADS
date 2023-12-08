#include <iostream>
#include <list>

#include "HashTable.hpp"

bool HashTable::__checkPrime(int value) {
	if (value <= 1) {
		return false;
	}
	for (int i = 2; i < value / 2; i++) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

int HashTable::__getPrime(int value) {
	while (!__checkPrime(value)) {
		value++;
	}
	return value;
}

int HashTable::__hashFunction(int key) {
	return(key % __capacity);
}

HashTable::HashTable(int value) {
	__capacity = __getPrime(value);
	__table = new std::list<std::pair<int, int>>[__capacity];
};

HashTable::~HashTable() {
	delete[] __table;
}

void HashTable::insertIntoTable(int key, int data) {
	int index = __hashFunction(key);
	__table[index].push_back(std::make_pair(key, data));
}

void HashTable::deleteFromTable(int key) {
	int index = __hashFunction(key);

	for (auto i = __table[index].begin(); i != __table[index].end();) {
		if (i->first == key) {
			__table[index].erase(i);
			break;
		}
		else {
			++i;
		}
	}
}

bool HashTable::searchKey(int key) {
	int index = __hashFunction(key);

	for (auto i = __table[index].begin(); i != __table[index].end();) {
		if (i->first == key) {
			return true;
		}
		else {
			++i;
		}
	}

	return false;

}

void HashTable::displayTable() {
	std::cout << "Your table is:";
	for (int i = 0; i < __capacity; i++) {
		std::cout << "\nTable[" << i << "]: ";
		bool skip = true;
		if (__table[i].empty()) {
			std::cout << "NULL";
		}
		else {
			std::cout << __table[i].front().second;
		}
		for (auto x : __table[i]) {
			if (skip) {
				skip = false;
				continue;
			}
			std::cout << "->" << x.second;
		}
		std::cout << std::endl;
			
	}
}