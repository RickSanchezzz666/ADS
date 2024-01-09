#pragma once

struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinarySearchTree {
public:
	Node* root;

	BinarySearchTree(int data);

	Node* insertIntoTree(Node* root, int data);
	int deleteFromTree(Node* root, int data);
	int searchInTree(Node* root, int data);
};