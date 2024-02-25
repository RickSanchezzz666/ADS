#pragma once
#include <iostream>

class Node {
private:
	int* keys;
	int nodeDegree;
	Node** children;
	int keysNum;
	bool leaf;

	void __displayTree();
	void __insertNonFull(int value);
	void __splitChild(Node* node, int i);

public:	
	Node(int d, bool l); // degree and leaf status

	friend class BTree;
};

class BTree {
private:
	Node* root;
	int treeDegree;
public:
	BTree(int t) : treeDegree(t), root(nullptr) {}; // degree

	void displayTree() {
		if (root != nullptr) {
			std::cout << "Your Tree: ";
			root->__displayTree();
			std::cout << std::endl;
		}
		else std::cerr << "\nBTree is Empty!\n";
	};

	void insertInTree(int value);
};