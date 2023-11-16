#include <iostream>

#define SIZE 5

struct Node {
	int data = NULL;
	struct Node *next = nullptr;
};

class LinkedList {
private:
	int __count = -1;
	Node* __head;

	Node* __createHead() {
		if (__count <= -1) {
			Node* head = new Node;
			++__count;
			return head;
		}
	}

	bool __isListEmpty() {
		if (__count <= 0 && __head->next == nullptr) { return true; } else { return false; };
	}

	bool __isListFull() {
		if(__count == SIZE) { return true; } else { return false; };
	}

public:
	LinkedList() : __count(-1) { __head = __createHead(); };

	~LinkedList() {
		Node* temp = __head;
		while (temp != nullptr) {
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
	}

	void addNode(int newData) {
		if (__isListFull() == true) { 
			std::cout << "The List is Full!\n";
			return; 
		}
		if (__count <= -1) {
			__createHead();
		}
		Node* newNode = new Node;
		Node* node = __head;
		while (node->next != nullptr) {
			node = node->next;
		}

		node->data = newData;
		node->next = newNode;
		++__count;
	}

	void deleteNode() {
		if (__isListEmpty() == true) {
			std::cout << "The List is Empty!\n";
			return;
		}
		Node* previous = nullptr;
		Node* node = __head;
		while (node->next != nullptr) {
			previous = node;
			node = node->next;
		}

		if (previous != nullptr) {
			delete node;
			previous->next = nullptr;
		}
		else {
			delete __head;
			__head = nullptr;
		}

		--__count;

	}

	void displayList() {
		if (__isListEmpty() == true) {
			std::cout << "The List is Empty!\n";
			return; 
		}
		else {
			std::cout << "Your List is:\nHEAD";
			Node* node = __head;
			for (int i = 0; i < __count; i++) {
				std::cout << "->" << node->data;
				node = node->next;
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
	list.addNode(105);
	list.addNode(26);

	list.deleteNode();

	list.displayList();
	return 0;
}