#pragma once

struct Node {
	int value;
	int degree = 0;
	Node* parent = nullptr;
	Node* child = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	// 'U' - undefined

	char mark = 'U';

	char C = 'U';

	Node(int v) : value(v) {}
};

class FibonacciHeap {
private:
	int nodesNum;
public:
	Node* rt; // root of Heap equal to minNode

	Node* initializeFHeap();
	FibonacciHeap() { rt = initializeFHeap(); }

	void displayFHeap(Node* root);

	Node* createNode(int value);
	Node* insertNode(Node* root, int value);

	Node* findNode(Node* root, int val);

	void fibonacciLink(Node* root, Node* y, Node* x);
	void consolidate(Node* root);
	Node* extractMin(Node* root);


};