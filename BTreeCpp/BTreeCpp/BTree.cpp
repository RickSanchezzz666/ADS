#include "BTree.hpp"

#include <iostream>

Node::Node(int d, bool l) {
	nodeDegree = d;
	leaf = l;

	keys = new int[2 * d - 1];
	children = new Node * [2 * d];

	keysNum = 0;
}


void Node::__displayTree() {
	int i;
	for (i = 0; i < keysNum; i++) {
		if (!leaf) children[i]->__displayTree();
		std::cout << "->" << keys[i];
	}

	if (!leaf) children[i]->__displayTree();
}

void Node::__insertNonFull(int value) {
	int i = keysNum - 1;
	if (leaf) {
		while (i >= 0 && keys[i] > value) {
			keys[i + 1] = keys[i];
			i--;
		}

		keys[i + 1] = value;
		keysNum++;
	} else {
		while (i >= 0 && keys[i] > value) i--;

		if (children[i + 1]->keysNum == 2 * nodeDegree - 1) {
			__splitChild(children[i + 1], i + 1);

			if (keys[i + 1] < value) i++;
		}

		children[i + 1]->__insertNonFull(value);
	}
}

void Node::__splitChild(Node* node, int i) {
	Node* tempNode = new Node(node->nodeDegree, node->leaf);
	tempNode->keysNum = nodeDegree - 1;

	for (int j = 0; j < nodeDegree - 1; j++) 
		tempNode->keys[j] = node->keys[j + nodeDegree];

	if (!tempNode->leaf) {
		for (int j = 0; j < nodeDegree; j++) 
			tempNode->children[j] = node->children[j + nodeDegree];
	}

	node->keysNum = nodeDegree - 1;
	for (int j = keysNum; j >= i + 1; j--)
		children[j + 1] = children[j];

	children[i + 1] = tempNode;

	for (int j = keysNum - 1; j >= i; j--)
		keys[j + 1] = keys[i];

	keys[i] = node->keys[nodeDegree - 1];
	keysNum++;
}


void BTree::insertInTree(int value) {
	if (root == nullptr) {
		root = new Node(treeDegree, true);
		root->keys[0] = value;
		root->keysNum = 1;
	} else {
		if (root->keysNum == 2 * treeDegree - 1) {
			Node* newNode = new Node(treeDegree, false);

			newNode->children[0] = root;

			newNode->__splitChild(root, 0);

			int i = 0;
			if (newNode->keys[0] < value) i++;
			newNode->children[i]->__insertNonFull(value);

			root = newNode;
		} else root->__insertNonFull(value);
	}
}

void BTree::deleteKey(int value) {
	if (!root) {
		std::cerr << "\nThe BTree is empty!\n";
		return;
	}

	root->__deleteKey(value);

	if (root->keysNum == 0) {
		Node* tmp = root;
		if (root->leaf) root = NULL;
		else root = root->children[0];

		delete tmp;
	}
	return;
}

Node* Node::__searcKey(int key) {
	if (key == keys[0]) return this;
	int i = 0;
	while (i < keysNum && key > keys[i]) i++;

	if (keys[i] == key) return this;

	if (leaf) return nullptr;

	return children[i]->__searcKey(key);
}

int Node::__searcKey(int key, bool intKey) {
	int index = 0;
	while (index < keysNum && keys[index] < key) index++;
	return index;
}

void Node::__deleteKey(int key) {
	int index = __searcKey(key, true);
	if (index < keysNum && keys[index] == key) {
		if (leaf) __deleteFromLeaf(index);
		else __deleteFromNonLeaf(index);
	}
	else {
		if (leaf) {
			std::cerr << "\nThe key " << key << " is not exist in this BTree!\n";
			return;
		}

		bool status = (index == keysNum ? true : false);

		if (children[index]->keysNum < nodeDegree) __fill(index);

		if (status && index > keysNum) children[index - 1]->__deleteKey(key);
		else children[index]->__deleteKey(key);
	}
	return;
}

void Node::__deleteFromLeaf(int index) {
	for (int i = index + 1; i < keysNum; ++i) keys[i - 1] = keys[i];
	keysNum--;
	return;
}

void Node::__deleteFromNonLeaf(int index) {
	int key = keys[index];

	if (children[index]->keysNum >= nodeDegree) {
		int pred = __getPredecessor(index);
		keys[index] = pred;
		children[index]->__deleteKey(pred);
	}
	else if (children[index + 1]->keysNum >= nodeDegree) {
		int succ = __getSuccessor(index);
		keys[index] = succ;
		children[index + 1]->__deleteKey(succ);
	}
	else {
		__mergeKeys(index);
		children[index]->__deleteKey(key);
	}
	return;
}

void Node::__fill(int index) {
	if (index != 0 && children[index - 1]->keysNum >= nodeDegree) __borrowFromPrev(index);
	else if (index != keysNum && children[index + 1]->keysNum >= nodeDegree) __borrowFromNext(index);
	else {
		if (index != keysNum) __mergeKeys(index);
		else __mergeKeys(index - 1);
	}
	return;
}

int Node::__getPredecessor(int index) {
	Node* cur = children[index];
	while (!cur->leaf)
		cur = cur->children[cur->keysNum];

	return cur->keys[cur->keysNum - 1];
}

int Node::__getSuccessor(int index) {
	Node* cur = children[index + 1];
	while (!cur->leaf)
		cur = cur->children[0];

	return cur->keys[0];
}

void Node::__mergeKeys(int index) {
	Node* child = children[index];
	Node* sibling = children[index + 1];

	child->keys[nodeDegree - 1] = keys[index];
	for (int i = 0; i < sibling->keysNum; ++i) child->keys[i + nodeDegree] = sibling->keys[i];

	if (!child->leaf) {
		for (int i = 0; i <= sibling->keysNum; ++i)
			child->children[i + nodeDegree] = sibling->children[i];
	}


	for (int i = index + 1; i < keysNum; ++i)
		keys[i - 1] = keys[i];

	for (int i = index + 2; i <= keysNum; ++i)
		children[i - 1] = children[i];

	child->keysNum += sibling->keysNum + 1;
	keysNum--;

	delete (sibling);
	return;
}

void Node::__borrowFromPrev(int index) {
	Node* child = children[index];
	Node* sibling = children[index - 1];

	for (int i = child->keysNum - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];

	if (!child->leaf) {
		for (int i = child->keysNum; i >= 0; --i)
			child->children[i + 1] = child->children[i];
	}

	child->keys[0] = keys[index - 1];

	if (!child->leaf)
		child->children[0] = sibling->children[sibling->keysNum];

	keys[index - 1] = sibling->keys[sibling->keysNum - 1];

	child->keysNum += 1;
	sibling->keysNum -= 1;

	return;
}

void Node::__borrowFromNext(int index) {
	Node* child = children[index];
	Node* sibling = children[index + 1];

	child->keys[child->keysNum] = keys[index];

	if (!child->keysNum)
		child->children[child->keysNum + 1] = sibling->children[0];
	
	keys[index] = sibling->keys[0];

	for (int i = 1; i < sibling->keysNum; ++i)
		sibling->keys[i - 1] = sibling->keys[i];

	if (!sibling->leaf) {
		for (int i = 1; i <= sibling->keysNum; ++i)
			sibling->children[i - 1] = sibling->children[i];
	}

	child->keysNum += 1;
	sibling->keysNum -= 1;

	return;
}
