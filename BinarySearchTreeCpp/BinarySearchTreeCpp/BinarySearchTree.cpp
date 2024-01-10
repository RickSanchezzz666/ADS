#include <iostream>
#include "BinarySearchTree.hpp"


BinarySearchTree::BinarySearchTree(int data) {
	root = new Node{ data };
}

void BinarySearchTree::__destructTree(Node* node) {
	if (node) {
		__destructTree(node->left);
		__destructTree(node->right);
		delete node;
	}
}

BinarySearchTree::~BinarySearchTree() {
	__destructTree(root);
}

void BinarySearchTree::traversalInOrder(Node* node) {
	if (node != nullptr) {
		traversalInOrder(node->left);
		std::cout << node->data << "->";
		traversalInOrder(node->right);
	}
}

Node* BinarySearchTree::insertIntoTree(Node* root, int data) {
	if (root == nullptr) return new Node{ data };
	if (data < root->data) root->left = insertIntoTree(root->left, data);
	else root->right = insertIntoTree(root->right, data);
	return root;
}

Node* BinarySearchTree::__minValueNode(Node* node) {
	Node* current = node;
	while (current != nullptr && current->left != nullptr) {
		current = current->left;
	}
	return current;
}

Node* BinarySearchTree::deleteFromTree(Node* root, int data) {
	if (root == nullptr) return root;
	if (data < root->data) root->left = deleteFromTree(root->left, data);
	else if (data > root->data) root->right = deleteFromTree(root->right, data);
	else {
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
		Node* temp = __minValueNode(root->right);

		root->data = temp->data;

		root->right = deleteFromTree(root->right, temp->data);
	}
	return root;
}
