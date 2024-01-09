#include "BinaryTree.hpp";
#include <iostream>
#include <cmath>

BinaryTree::BinaryTree(int data) {
	root = new Node;
	root->data = data;
}

void BinaryTree::__destructTheTree(Node* node) {
	if (node) {
		__destructTheTree(node->left);
		__destructTheTree(node->right);
		delete node;
	}
}

BinaryTree::~BinaryTree() {
	__destructTheTree(root);
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


int BinaryTree::__depth(Node* node) {
	int d = 0;
	while (node != nullptr) {
		d++;
		node = node->left;
	}
	return d;
}

bool BinaryTree::__isTreePerfectCheck(Node* root, int d, int level) {
	if (root == nullptr) return true;

	if (root->left == nullptr && root->right == nullptr) return (d == level + 1);

	if (root->left == nullptr || root->right == nullptr) return false;

	return __isTreePerfectCheck(root->left, d, level + 1) && __isTreePerfectCheck(root->right, d, level + 1);
}

bool BinaryTree::isTreePerfect(Node* root) {
	int d = __depth(root);
	return __isTreePerfectCheck(root, d);
}

int BinaryTree::__nodesCount(Node* node) {
	if (node == nullptr) return 0;
	return (1 + __nodesCount(node->left) + __nodesCount(node->right));
}

bool BinaryTree::__isTreeCompleteCheck(Node* root, int nodesNum, int index) {
	if (root == nullptr) return true;
	if (index >= nodesNum) return false;

	return __isTreeCompleteCheck(root->left, nodesNum, 2 * index + 1) && __isTreeCompleteCheck(root->right, nodesNum, 2 * index + 2);
}

bool BinaryTree::isTreeComplete(Node* root) {
	int nodesNum = __nodesCount(root);
	return __isTreeCompleteCheck(root, nodesNum);
}

bool BinaryTree::isTreeBalanced(Node* root, int *height) {
	int leftHeight = 0, rightHeight = 0, l = 0, r = 0;

	if (root == nullptr) {
		*height = 0;
		return true;
	}

	l = isTreeBalanced(root->left, &leftHeight);
	r = isTreeBalanced(root->right, &rightHeight);

	*height = std::max(leftHeight, rightHeight) + 1;

	if (std::abs((leftHeight - rightHeight) >= 2)) return false;
	else return l && r;

}




