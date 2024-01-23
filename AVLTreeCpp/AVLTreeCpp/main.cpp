#include "AVLTree.hpp"

#include <iostream>

int main() {
	AVLTree tree(6);
	Node* root = tree.root;

	root = tree.insertNode(root, 5);
	root = tree.insertNode(root, 2);
	root = tree.insertNode(root, 1);
	root = tree.insertNode(root, 8);
	root = tree.insertNode(root, 21);
	root = tree.insertNode(root, 10);

	tree.treeTraversalInOrder(root);

	root = tree.deleteNode(root, 8);

	std::cout << "\nAfter deleting: ";

	tree.treeTraversalInOrder(root);
	return 0;
}