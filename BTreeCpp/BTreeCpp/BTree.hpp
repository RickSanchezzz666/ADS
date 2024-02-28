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
	Node* __searcKey(int key);
	int __searcKey(int key, bool intKey);
	void __deleteKey(int key);
	void __deleteFromLeaf(int index);
	void __deleteFromNonLeaf(int index);
	void __fill(int index);
	int __getPredecessor(int index);
	int __getSuccessor(int index);
	void __mergeKeys(int index);
	void __borrowFromPrev(int index);
	void __borrowFromNext(int index);

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

	Node* searchKey(int key) {
		if (root != nullptr) {
			std::cout << "\nYou searched for: " << key << std::endl;
			return root->__searcKey(key);
		}
		else std::cerr << "\nBTree is Empty!\n";
	}

	void deleteKey(int value);

	void insertInTree(int value);
};