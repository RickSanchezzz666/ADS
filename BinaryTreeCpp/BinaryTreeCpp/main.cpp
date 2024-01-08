#include "BinaryTree.hpp";
#include <iostream>;

int main() {
	BinaryTree tree(1);

	tree.root->left = tree.newNode(5);
	tree.root->right = tree.newNode(3);
	tree.root->left->left = tree.newNode(10);
	tree.root->left->right = tree.newNode(8);

	std::cout << "InOrderTraversal: ";
	tree.traversalInOrder(tree.root);

	std::cout << "\nPreOrderTraversal: ";
	tree.traversalPreOrder(tree.root);

	std::cout << "\nPostOrderTraversal: ";
	tree.traversalPostOrder(tree.root);

	//BinaryTreeTypes

	std::cout << "\nIs This Tree is Full: ";
	bool full = tree.isTreeFull(tree.root);
	std::cout << (full ? "True" : "False") << std::endl;

	return 0;
}