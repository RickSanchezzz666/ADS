#pragma once

struct Node {
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
	int height = 1;
};

class AVLTree {
private:
	int __getHeight(Node* node);
	int __getBalanceFactor(Node* node);
	int __getMax(int x, int y);
	Node* __getMinValNode(Node* node);
	void __updateHeight(Node* node);

	void __destructTree(Node* node);

	Node* leftRotate(Node* x);
	Node* rightRotate(Node* y);

	Node* updateBalanceFactor(Node* node, int key);

public:
	Node* root;

	AVLTree(int key);
	~AVLTree();

	void treeTraversalInOrder(Node* node);
	Node* insertNode(Node* node, int key);
	Node* deleteNode(Node* node, int key);
};