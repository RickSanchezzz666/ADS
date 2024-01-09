#include "BinaryTree.hpp";
#include <iostream>;

static void checkTreeType(BinaryTree tree, BinaryTreeType type);
static void doTreeTraversal(BinaryTree tree, TreeTraversalType type);

int main() {
	BinaryTree tree(1);

	tree.root->left = tree.newNode(5);
	tree.root->right = tree.newNode(3);
	tree.root->left->left = tree.newNode(10);
	tree.root->left->right = tree.newNode(8);

	doTreeTraversal(tree, TreeTraversalType::INORDER);

	doTreeTraversal(tree, TreeTraversalType::PREORDER);

	doTreeTraversal(tree, TreeTraversalType::POSTORDER);

	//BinaryTreeTypes

	//Full
	checkTreeType(tree, BinaryTreeType::FULL);

	//Perfect
	tree.root->right->left = tree.newNode(20);
	tree.root->right->right = tree.newNode(15);

	checkTreeType(tree, BinaryTreeType::PERFECT);

	//Complete
	checkTreeType(tree, BinaryTreeType::COMPLETE);

	//Balanced
	checkTreeType(tree, BinaryTreeType::BALANCED);

	return 0;
}

static void checkTreeType(BinaryTree tree, BinaryTreeType type) {
	switch (type)
	{
	case BinaryTreeType::FULL: {
		std::cout << "\nIs This Tree is Full: ";
		bool full = tree.isTreeFull(tree.root);
		std::cout << (full ? "True" : "False") << std::endl;
		break;
	}
	case BinaryTreeType::PERFECT: {
		std::cout << "\nIs This Tree is Perfect: ";
		bool perfect = tree.isTreePerfect(tree.root);
		std::cout << (perfect ? "True" : "False") << std::endl;
		break;
	}
	case BinaryTreeType::COMPLETE: {
		std::cout << "\nIs This Tree is Complete: ";
		bool complete = tree.isTreeComplete(tree.root);
		std::cout << (complete ? "True" : "False") << std::endl;
		break;
	}
	case BinaryTreeType::BALANCED: {
		int height = 0;

		std::cout << "\nIs This Tree is Balanced: ";
		bool balanced = tree.isTreeBalanced(tree.root, &height);
		std::cout << (balanced ? "True" : "False") << std::endl;
		break;
	}
	default:
		break;
	}
}

void doTreeTraversal(BinaryTree tree, TreeTraversalType type)
{
	switch (type)
	{
	case TreeTraversalType::INORDER:
		std::cout << "\nInOrderTraversal: ";
		tree.traversalInOrder(tree.root);
		break;
	case TreeTraversalType::PREORDER:
		std::cout << "\nPreOrderTraversal: ";
		tree.traversalPreOrder(tree.root);
		break;
	case TreeTraversalType::POSTORDER:
		std::cout << "\nPostOrderTraversal: ";
		tree.traversalPostOrder(tree.root);
		break;
	default:
		break;
	}
}
