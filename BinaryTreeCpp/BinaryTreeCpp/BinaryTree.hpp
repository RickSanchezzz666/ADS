#pragma once

enum class BinaryTreeType {
	FULL,
	PERFECT,
	COMPLETE,
	BALANCED
};

enum class TreeTraversalType {
	INORDER,
	PREORDER,
	POSTORDER
};

struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinaryTree {
private:
	int __depth(Node* node);
	bool __isTreePerfectCheck(Node* root, int d, int level = 0);

	int __nodesCount(Node* node);
	bool __isTreeCompleteCheck(Node* root, int nodesNum, int index = 0);
public:
	Node* root;

	BinaryTree(int data);
	Node* newNode(int data);
	void traversalInOrder(Node* node);
	void traversalPreOrder(Node* node);
	void traversalPostOrder(Node* node);

	bool isTreeFull(Node* root);
	bool isTreePerfect(Node* root);
	bool isTreeComplete(Node* root);
	bool isTreeBalanced(Node* root, int *height);
	//TODO: Make different types of Trees
};