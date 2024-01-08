#pragma once

struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinaryTree {
public:
	Node* root;

	BinaryTree(int data);
	Node* newNode(int data);
	void traversalInOrder(Node* node);
	void traversalPreOrder(Node* node);
	void traversalPostOrder(Node* node);

	bool isTreeFull(Node* root);

	//TODO: Make different types of Trees
};