#include "FibonacciHeap.hpp"

#include <iostream>
#include <cmath>
#include <vector>

Node* FibonacciHeap::initializeFHeap() {
	Node* np;
	np = nullptr;
    return np;
}

void FibonacciHeap::displayFHeap(Node* root) {
	Node* node = root;
	Node* r = root;
	if (r == nullptr) {
		std::cerr << "\nHeap is Empty\n";
		return;
	}
	std::cout << "\nRoot nodes:\n";
	do {
		std::cout << r->value;
		r = r->right;
		if (r != root) std::cout << "->";
	} while (r != root && r->right != nullptr);
	std::cout << std::endl;
}

Node* FibonacciHeap::createNode(int value) {
	Node* newNode = new Node(value);
	return newNode;
}

Node* FibonacciHeap::insertNode(Node* root, int value) {
    Node* newNode = createNode(value);
    newNode->left = newNode;
    newNode->right = newNode;
    newNode->mark = 'F';
    newNode->C = 'N';
    
    if (root != nullptr) {
		root->left->right = newNode;
        newNode->right = root;
        newNode->left = root->left;
        root->left = newNode;
        if (newNode->value < root->value) {
            root = newNode;
        }
    } else {
        root = newNode;
    }
    nodesNum++;
    return root;
}


Node* FibonacciHeap::fibonacciLink(Node* root, Node* y, Node* x) {
	y->left->right = y->right;
	y->right->left = y->left;

	if (x->child == nullptr) x->child = y;

	y->right = x->child->right;
	y->left = x->child;
	x->child->right->left = y;
	x->child->right = y;

	if (y->value < x->child->value) x->child = y;
	y->parent = x;
	x->degree++;

	return x;
}



Node* FibonacciHeap::consolidate(Node* root) {
	int degree;
	float f = (log(nodesNum)) / (log(2));
	int size = f;
	std::vector<Node*> arr((size + 1), nullptr);
	Node* x = root;
	Node* y;
	Node* z;
	Node* pt = x;

	do {
		pt = pt->right;
		degree = x->degree;
		while (arr[degree] != nullptr) {
			y = arr[degree];
			if (x->value > y->value) {
				z = x;
				x = y;
				y = z;
			}
			if (y == root) root = root->right;
			x = fibonacciLink(root, y, x);
			y->mark = 'C';

			arr[degree] = nullptr;
			degree++;
		}

		arr[degree] = x;
		x = pt;
	} while (x != root);

	root = nullptr;
	Node* minNode = nullptr;

	for (int j = 0; j <= degree; j++) {
		if (arr[j] != nullptr) {
			if (root != nullptr) {
				root->left->right = arr[j];
				arr[j]->right = root;
				arr[j]->left = root->left;
				root->left = arr[j];
				if (arr[j]->value < root->value) root = arr[j];
			}
			else {
				root = arr[j];
				minNode = arr[j];
			}
			if (minNode == nullptr || arr[j]->value < minNode->value) minNode = arr[j];
		}
	}

	return minNode;
}

Node* FibonacciHeap::extractMin(Node* root) {
	if (root == nullptr) return root;
	Node* z = root;
	Node* ptr = z;
	Node* x = nullptr;

	if (z->child != nullptr) {
		x = z->child;
		do {
			ptr = x->right;
			x->parent = nullptr;
			x = ptr;
		} while (ptr != z->child);
	}
	if (z == z->right && z->child == nullptr) {
		delete z;
		return nullptr;
	} else {
		z->left->right = z->right;
		z->right->left = z->left;
		Node* newRoot = z->right;
		newRoot = consolidate(newRoot);
		delete z;
		nodesNum--;
		Node* min = newRoot;
		Node* temp = newRoot->right;
		do {
			if (temp->value < min->value) min = temp;
			temp = temp->right;
		} while (temp != newRoot);

		return min;
	}
}

/*
Node* FibonacciHeap::findNode(Node* root, int val) {
	Node* x = root;
	x->C = 'Y';
	Node* search = nullptr;
	if (x->value == val) {
		search = x;
		x->C = 'N';
		return search;
	}

	if (search == nullptr) {
		if (x->child != nullptr) search = findNode(x->child, val);
		if (search != nullptr && search->value == val) return search;

		if (x->right->C != 'Y') search = findNode(x->right, val);
		if (search != nullptr && search->value == val) return search;
	}
	x->C = 'N';
	return search;
}

void FibonacciHeap::cutNode(Node* root, Node* x, Node* y) {
	if (x == x->right) y->right = nullptr;
	x->left->right = x->right;
	x->right->left = x->left;
	if (x == y->child) y->child = x->right;
	y->degree--;
	x->right = x;
	x->left = x;
	root->left->right = x;
	x->right = root;
	x->left = root->left;
	root->left = x;
	x->parent = nullptr;
	x->mark = 'F';
}

void FibonacciHeap::cascadeCutNode(Node* root, Node* y) {
	Node* z = y->parent;
	if (z != nullptr) {
		if (y->mark == 'F') y->mark = 'T';
		else {
			cutNode(root, y, z);
			cascadeCutNode(root, z);
		}
	} 
}

bool FibonacciHeap::decreaseKeyOfNode(Node* root, int val, int decreaseVal) {
	if (root == nullptr) {
		std::cerr << "\nHeap is Empty\n";
		return false;
	}
	Node* ptr = findNode(root, val);
	if (ptr == nullptr) {
		std::cerr << "\nSuch key was not found!\n";
		return false;
	}
	ptr->value = decreaseVal;
	Node* y;
	y = ptr->parent;
	if (y != nullptr && ptr->value < y->value) {
		cutNode(root, ptr, y);
		cascadeCutNode(root, y);
	}
	if (ptr->value < rt->value) {
		rt = ptr;
	}
	return true;
}

bool FibonacciHeap::deleteKey(Node* root, int val) {
	Node* np = nullptr;
	int temp = decreaseKeyOfNode(root, val, -99999);
	if (!temp) np = extractMin(rt);
	if (np != nullptr) return true;
	return false;
}

*/