#include "FibonacciHeap.hpp"

#include <iostream>

int main() {
	FibonacciHeap fHeap;
	Node* root = fHeap.initializeFHeap();
	root = fHeap.insertNode(root, 5);
	root = fHeap.insertNode(root, 3);
	root = fHeap.insertNode(root, 8);
	root = fHeap.insertNode(root, 15);
	fHeap.displayFHeap(root);

	Node* minNode = fHeap.extractMin(root);

	std::cout << "Min Node value: " << minNode->value << std::endl;

	int numToSearch = 8;

	Node* foundNode = fHeap.findNode(root, numToSearch);

	bool foundValue = (foundNode != nullptr ? true : false);

	std::cout << "Found status of " << numToSearch << ": " << (foundNode ? "True" : "False") << std::endl;

	return 0;
}