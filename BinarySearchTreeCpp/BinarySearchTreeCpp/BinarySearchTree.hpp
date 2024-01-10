#pragma once

struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinarySearchTree {
private:
	void __destructTree(Node* node);

	Node* __minValueNode(Node* node);

public:
	Node* root;

	BinarySearchTree(int data);
	~BinarySearchTree();

	void traversalInOrder(Node* node);

	Node* insertIntoTree(Node* root, int data);
	Node* deleteFromTree(Node* root, int data);
};