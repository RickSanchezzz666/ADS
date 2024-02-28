#include "BTree.hpp"

#include <iostream>

int main() {
	BTree tree(3);
	tree.insertInTree(5);
	tree.insertInTree(13);
	tree.insertInTree(8);
	tree.insertInTree(31);
	tree.insertInTree(35);

	tree.displayTree();

	tree.insertInTree(11);
	
	tree.displayTree();

	Node* searchNode = tree.searchKey(31);
	std::cout << "Is it found? - " << (searchNode != nullptr ? "True" : "false") << std::endl;

	Node* searchNode2 = tree.searchKey(12);
	std::cout << "Is it found? - " << (searchNode2 != nullptr ? "True" : "false") << "\n\n";

	tree.displayTree();

	std::cout << "\nTrying to delete: 31\n";

	tree.deleteKey(31);

	tree.displayTree();

	std::cout << "\nTrying to delete: 5\n";

	tree.deleteKey(5);

	tree.displayTree();


	return 0;
}