#include "AVLTree.hpp"

#include <iostream>

AVLTree::AVLTree(int key) {
	root = new Node{key};
}

AVLTree::~AVLTree() {
	__destructTree(root);
}

int AVLTree::__getMax(int x, int y) {
	return (x > y) ? x : y;
}

int AVLTree::__getHeight(Node* node) {
	if (node != nullptr) return node->height;
	return 0;
}

int AVLTree::__getBalanceFactor(Node* node) {
	if (node != nullptr) return __getHeight(node->left) - __getHeight(node->right);
	return 0;
}

Node* AVLTree::__getMinValNode(Node* node) {
	Node* current = node;
	while (current->left != nullptr) current = current->left;
	return current;
}

void AVLTree::__updateHeight(Node* node) {
	node->height = __getMax(__getHeight(node->left), __getHeight(node->right)) + 1;
}

void AVLTree::__destructTree(Node* node) {
	if (node) {
		__destructTree(node->left);
		__destructTree(node->right);
		delete node;
	}
}

void AVLTree::treeTraversalInOrder(Node* node) {
	if (node) {
		treeTraversalInOrder(node->left);
		std::cout << (node->key == root->key ? "root:" : "") << node->key << "->";
		treeTraversalInOrder(node->right);
	}
}

Node* AVLTree::updateBalanceFactor(Node* node, int key) {
	__updateHeight(node);
	int balanceFactor = __getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (key < node->left->key) return rightRotate(node);
		else if (key > node->left->key) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (key > node->right->key) return leftRotate(node);
		else if (key < node->right->key) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

Node* AVLTree::leftRotate(Node* x) {
	Node* y = x->right;
	Node* temp = y->left;
	y->left = x;
	x->right = temp;
	__updateHeight(x);
	__updateHeight(y);
	return y;
}

Node* AVLTree::rightRotate(Node* y) {
	Node* x = y->left;
	Node* temp = x->right;
	x->right = y;
	y->left = temp;
	__updateHeight(y);
	__updateHeight(x);
	return x;
}


Node* AVLTree::insertNode(Node* node, int key) {
	if (node == nullptr) return new Node{ key };
	if (key < node->key) node->left = insertNode(node->left, key);
	else if (key > node->key) node->right = insertNode(node->right, key);
	else return node;

	return updateBalanceFactor(node, key);
}

Node* AVLTree::deleteNode(Node* node, int key) {
	if (node == nullptr) return node;
	if (key < node->key) node->left = deleteNode(node->left, key);
	else if (key > node->key) node->right = deleteNode(node->right, key);
	else {
		if (node->left == nullptr || node->right == nullptr) {
			Node* temp = node->left ? node->left : node->right;
			if (temp == nullptr) {
				temp = node;
				node = nullptr;
			}
			else {
				*node = *temp;
				delete temp;
			}
		}
		else {
			Node* temp = __getMinValNode(node->right);
			node->key = temp->key;
			node->right = deleteNode(node->right, temp->key);
		}
	}

	if (node == nullptr) return node;

	return updateBalanceFactor(node, key);
}
