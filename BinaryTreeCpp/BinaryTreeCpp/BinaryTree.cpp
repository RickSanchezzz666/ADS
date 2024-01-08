#include "BinaryTree.hpp";
#include <iostream>

BinaryTree::BinaryTree(int data) {
	root = new Node;
	root->data = data;
}

Node* BinaryTree::newNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;

	return newNode;
}

void BinaryTree::traversalInOrder(Node* node) {
	if (node) {
		traversalInOrder(node->left);
		std::cout << node->data << "->";
		traversalInOrder(node->right);
	}
}

void BinaryTree::traversalPreOrder(Node* node) {
	if (node) {
		std::cout << node->data << "->";
		traversalInOrder(node->left);
		traversalInOrder(node->right);
	}
}

void BinaryTree::traversalPostOrder(Node* node) {
	if (node) {
		traversalInOrder(node->left);
		traversalInOrder(node->right);
		std::cout << node->data << "->";
	}
}

bool BinaryTree::isTreeFull(Node* root) {
	if (root == nullptr) return true;

	if (root->left == nullptr && root->right == nullptr) return true;

	if (root->left && root->right) return (isTreeFull(root->left) && isTreeFull(root->right));

	return false;
}
