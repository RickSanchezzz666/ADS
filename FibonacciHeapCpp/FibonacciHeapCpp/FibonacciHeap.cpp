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
	Node* r = root;
	if (r == nullptr) {
		std::cerr << "\n Heap is Empty\n";
		return;
	}
	std::cout << "Root nodes:\n";
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

Node* FibonacciHeap::insertNode(Node* root, int value){
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
	}
	else {
		root = newNode;
	}
	nodesNum = nodesNum + 1;
	return root;
}


void FibonacciHeap::fibonacciLink(Node* root, Node* y, Node* x) {
	y->left->right = y->right;
	y->right->left = y->left;
	if (x->right == x) root = x;
	y->left = y;
	y->right = y;
	y->parent = x;

	if (x->child == nullptr) x->child = y;

	y->right = x->child;
	y->left = x->child->left;
	x->child->left->right = y;
	x->child->left = y;

	if (y->value < x->child->value) x->child = y;
	x->degree++;
}



void FibonacciHeap::consolidate(Node* root) {
	int degree;
	float f = (log(nodesNum)) / (log(2));
	int size = f;
	std::vector<Node*> arr(size + 1);
	for (int i = 0; i <= size; i++) arr[i] = nullptr;
	Node* x = root;
	Node* y;
	Node* temp;
	Node* pt = x;

	do {
		pt = pt->right;
		degree = x->degree;
		while (arr[degree] != nullptr){
			y = arr[degree];
			if (x->value > y->value) {
				temp = x;
				x = y;
				y = temp;
			}
			if (y == root) root = x;
			fibonacciLink(root, y, x);

			if (x->right == x) root = x;
			arr[degree] = nullptr;
			degree = degree + 1;
		}

		arr[degree] = x;
		x = x->right;
	} while (x != root);

	rt = nullptr;

	for (int j = 0; j <= degree; j++) {
		if (arr[j] != nullptr) {
			arr[j]->left = arr[j];
			arr[j]->right = arr[j];
			if (rt != nullptr) {
				rt->left->right = arr[j];
				arr[j]->right = rt;
				arr[j]->left = rt->left;
				rt->left = arr[j];
				if (arr[j]->value < rt->value) rt = arr[j];
			}
			else rt = arr[j];

			if (rt == nullptr) rt = arr[j];
			else if (arr[j]->value < rt->value) rt = arr[j];
		}
	}
}

Node* FibonacciHeap::extractMin(Node* root) {
	Node* p;
	Node* ptr;
	Node* z = root;
	p = z;
	ptr = z;
	if (z == nullptr) return z;
	
	Node* x;
	x = nullptr;
	Node* np;

	if (z->child != nullptr) x = z->child;

	if (x != nullptr) {
		ptr = x;
		do{
			np = x->right;
			root->left->right = x;
			x->right = root;
			x->left = root->left;
			root->left = x;
			if (x->value < root->value) root = x;

			x->parent = nullptr;
			x = np;
		} while (np != ptr);
	}

	z->left->right = z->right;
	z->right->left = z->left;
	root = z->right;

	if (z == z->right && z->child == nullptr) rt = nullptr;
	else {
		root = z->right;
		consolidate(root);
	}
	nodesNum = nodesNum - 1;
	rt = z;
	return p;
}

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