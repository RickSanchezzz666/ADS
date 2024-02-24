#include "FibonacciHeap.hpp"

#include <iostream>

int main() {
	FibonacciHeap fHeap;
	Node* root = fHeap.initializeFHeap();
	root = fHeap.insertNode(root, 5);
	root = fHeap.insertNode(root, 18);
	root = fHeap.insertNode(root, 3);
	root = fHeap.insertNode(root, 8);
	root = fHeap.insertNode(root, 2);
	root = fHeap.insertNode(root, 15);

	fHeap.displayFHeap(root);

	root = fHeap.extractMin(root);

	fHeap.displayFHeap(root);


	/*

	int numToSearch = 8;
	Node* foundNode = fHeap.findNode(root, numToSearch);
	bool foundValue = (foundNode != nullptr ? true : false);
	std::cout << "Found status of " << numToSearch << ": " << (foundNode ? "True" : "False") << std::endl;
	

	int numToDelete = 18;
	bool deleteKey = fHeap.deleteKey(root, numToDelete);

	std::cout << "Delete key " << numToDelete << ": " << (deleteKey ? "True" : "False") << std::endl;
	*/
	return 0;
}