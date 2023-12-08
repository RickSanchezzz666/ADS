#pragma once

#include <list>

class HashTable {
private:
	int __capacity;
	std::list<std::pair<int, int>>* __table;

	bool __checkPrime(int value);

	int __getPrime(int value);

	int __hashFunction(int key);

public:

	HashTable(int value);

	void insertIntoTable(int key, int data);

	void deleteFromTable(int key);

	bool searchKey(int key);

	void displayTable();

	~HashTable();
};