#include <iostream>
#include "HashTable.hpp"

int main() {
	int keys[] = { 123, 321, 332, 445, 556, 666, 312, 12, 35, 525, 665, 22 };
	int data[] = { 51, 559, 12, 49, 92, 3, 213, 22, 11, 42, 23, 53 };

	int size = sizeof(keys) / sizeof(keys[0]);

	HashTable table(size);

	for (int i = 0; i < size; i++) {
		table.insertIntoTable(keys[i], data[i]);
	}

	table.deleteFromTable(321);

	table.displayTable();

	int elem = table.searchKey(22);

	std::cout << "\nMy element was found: " << (elem ? "True" : "False") << std::endl;


	return 0;
};