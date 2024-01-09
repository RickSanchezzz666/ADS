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

	//Full
	std::cout << "\nIs This Tree is Full: ";
	bool full = tree.isTreeFull(tree.root);
	std::cout << (full ? "True" : "False") << std::endl;

	//Perfect
	tree.root->right->left = tree.newNode(20);
	tree.root->right->right = tree.newNode(15);

	std::cout << "\nIs This Tree is Perfect: ";
	bool perfect = tree.isTreePerfect(tree.root);
	std::cout << (perfect ? "True" : "False") << std::endl;

	return 0;
}