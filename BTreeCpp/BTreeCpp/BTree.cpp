#include "BTree.hpp"

#include <iostream>

Node::Node(int d, bool l) {
	nodeDegree = d;
	leaf = l;

	keys = new int[2 * d - 1];
	children = new Node * [2 * d];

	keysNum = 0;
}


void Node::__displayTree() {
	int i;
	for (i = 0; i < keysNum; i++) {
		if (!leaf) children[i]->__displayTree();
		std::cout << "->" << keys[i];
	}

	if (!leaf) children[i]->__displayTree();
}

void Node::__insertNonFull(int value) {
	int i = keysNum - 1;
	if (leaf) {
		while (i >= 0 && keys[i] > value) {
			keys[i + 1] = keys[i];
			i--;
		}

		keys[i + 1] = value;
		keysNum++;
	} else {
		while (i >= 0 && keys[i] > value) i--;

		if (children[i + 1]->keysNum == 2 * nodeDegree - 1) {
			__splitChild(children[i + 1], i + 1);

			if (keys[i + 1] < value) i++;
		}

		children[i + 1]->__insertNonFull(value);
	}
}

void Node::__splitChild(Node* node, int i) {
	Node* tempNode = new Node(node->nodeDegree, node->leaf);
	tempNode->keysNum = nodeDegree - 1;

	for (int j = 0; j < nodeDegree - 1; j++) 
		tempNode->keys[j] = node->keys[j + nodeDegree];

	if (!tempNode->leaf) {
		for (int j = 0; j < nodeDegree; j++) 
			tempNode->children[j] = node->children[j + nodeDegree];
	}

	node->keysNum = nodeDegree - 1;
	for (int j = keysNum; j >= i + 1; j--)
		children[j + 1] = children[j];

	children[i + 1] = tempNode;

	for (int j = keysNum - 1; j >= i; j--)
		keys[j + 1] = keys[i];

	keys[i] = node->keys[nodeDegree - 1];
	keysNum++;
}

void BTree::insertInTree(int value) {
	if (root == nullptr) {
		root = new Node(treeDegree, true);
		root->keys[0] = value;
		root->keysNum = 1;
	} else {
		if (root->keysNum == 2 * treeDegree - 1) {
			Node* newNode = new Node(treeDegree, false);

			newNode->children[0] = root;

			newNode->__splitChild(root, 0);

			int i = 0;
			if (newNode->keys[0] < value) i++;
			newNode->children[i]->__insertNonFull(value);

			root = newNode;
		} else root->__insertNonFull(value);
	}
}
