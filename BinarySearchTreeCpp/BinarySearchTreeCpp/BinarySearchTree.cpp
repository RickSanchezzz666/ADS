#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree(int data) {
	root = new Node{ data };
}

Node* BinarySearchTree::insertIntoTree(Node* root, int data) {
	if (root == nullptr) return new Node{ data };
}
