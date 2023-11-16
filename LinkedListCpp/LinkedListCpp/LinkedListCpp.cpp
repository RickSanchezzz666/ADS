#include <iostream>

#define SIZE 5

struct Node {
	int data = NULL;
	struct Node *next = NULL;
};

class LinkedList {
private:
	int __count = -1;
	Node* items = new Node[SIZE];

	void __createHead() {
		if (__count <= -1) {
			Node* head = new Node;
			++__count;
			items[__count] = *head;
		}
	}

	bool __isListEmpty() {
		if (__count <= 0) { return true; } else { return false; };
	}

	bool __isListFull() {
		if(__count == SIZE - 1 && items[__count].next == NULL) { return true; } else { return false; };
	}

public:
	LinkedList() : __count(-1) { __createHead(); };

	~LinkedList() {
		delete[] items;
	}


	void addNode(int newData) {
		if (__isListFull() == true) { 
			std::cout << "The List is Full!";
			return; 
		}
		if (__count <= -1) {
			__createHead();
		}
		else {
			Node* node = new Node;
			Node* previousNode = &items[__count];
			previousNode->data = newData;
			previousNode->next = node;
			++__count;
			items[__count] = *node;
		}
	}

	void displayList() {
		if (__isListEmpty() == true) {
			std::cout << "The List is Empty!\n";
			return; 
		}
		else {
			std::cout << "Your List is:\nHEAD";
			for (int i = 0; i < __count; i++) {
				std::cout << "->" << items[i].data;
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	LinkedList list;
	
	list.addNode(5);
	list.addNode(11);
	list.addNode(15);

	list.displayList();
	return 0;
}