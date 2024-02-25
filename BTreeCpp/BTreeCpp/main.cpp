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

	return 0;
}