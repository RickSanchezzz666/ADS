#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
	BinarySearchTree tree(6);
	Node* root = tree.root;

	root = tree.insertIntoTree(root, 4);
	root = tree.insertIntoTree(root, 2);
	root = tree.insertIntoTree(root, 1);
	root = tree.insertIntoTree(root, 7);
	root = tree.insertIntoTree(root, 9);
	root = tree.insertIntoTree(root, 12);
	root = tree.insertIntoTree(root, 8);

	std::cout << "Tree Traversal In Order: ";
	tree.traversalInOrder(root);
	std::cout << std::endl;

	root = tree.deleteFromTree(root, 7);
	root = tree.deleteFromTree(root, 4);

	std::cout << "Tree Traversal In Order: ";
	tree.traversalInOrder(root);
	std::cout << std::endl;

	return 0;
}