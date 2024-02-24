#pragma once

struct Node {
	int value;
	int degree = 0;
	Node* parent = nullptr;
	Node* child = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	// 'U' - undefined

	char mark = 'U';

	char C = 'U';

	Node(int v) : value(v) {}
};

class FibonacciHeap {
private:
	int nodesNum = 0;


public:
	Node* initializeFHeap();

	void displayFHeap(Node* root);

	Node* createNode(int value);
	Node* insertNode(Node* root, int value);

	Node* findNode(Node* root, int val);

	Node* fibonacciLink(Node* root, Node* y, Node* x);
	Node* consolidate(Node* root);
	Node* extractMin(Node* root);

	void cutNode(Node* root, Node* x, Node* y);
	void cascadeCutNode(Node* root, Node* x);
	bool decreaseKeyOfNode(Node* root, int val, int decreaseVal);
	bool deleteKey(Node* root, int val);
};

/*
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



	int numToSearch = 8;
	Node* foundNode = fHeap.findNode(root, numToSearch);
	bool foundValue = (foundNode != nullptr ? true : false);
	std::cout << "Found status of " << numToSearch << ": " << (foundNode ? "True" : "False") << std::endl;


	int numToDelete = 18;
	bool deleteKey = fHeap.deleteKey(root, numToDelete);

	std::cout << "Delete key " << numToDelete << ": " << (deleteKey ? "True" : "False") << std::endl;
	return 0;
}
*/