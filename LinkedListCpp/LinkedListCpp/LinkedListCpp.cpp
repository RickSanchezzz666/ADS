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
			__count = 0;
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

	void addNode(int newData, int nodePos = -1) {
		if (__isListFull() == true) { 
			std::cout << "The List is Full!\n";
			return; 
		}
		if (nodePos == -1) {
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
		else {
			if (nodePos > __count || nodePos < 1) {
				std::cout << "The Node was not found!\n";
				return; 
			} else {
				Node* newNode = new Node;
				newNode->data = newData;

				if (__count <= -1) {
					__createHead();
				}
				Node* node = __head;
				for (int i = 1; i < nodePos; i++) {
					if (node->next != nullptr) {
						node = node->next;
					}
					else {
						std::cout << "The Node was not found!\n";
						delete newNode;
						return;
					}
				}
				newNode->next = node->next;
				node->next = newNode;
				++__count;
			};
		}
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

	Node* searchNode(int nodePos) {
		if (nodePos > __count || nodePos < 1) {
			std::cout << "The Node was not found!\n";
			return nullptr;
		} else {
			Node* node = __head;
			for (int i = 1; i < nodePos; i++) {
				if (node->next != nullptr) {
					node = node->next;
				} else {
					std::cout << "The Node was not found!\n";
					return nullptr;
				}
			}
			return node;
		}
	}

	void displayList() {
		if (__isListEmpty() == true) {
			std::cout << "The List is Empty!\n";
			return; 
		} else {
			std::cout << "Your List is:\nHEAD";
			Node* node = __head;
			for (int i = 0; i < __count; i++) {
				std::cout << "->" << node->data;
				node = node->next;
			}
			std::cout << std::endl;
		}
	}

	void sortList() {
		if (__isListEmpty()) {
			std::cout << "The List is Empty!\n";
			return;
		}

		bool swapped;
		do {
			swapped = false;
			Node* previous = nullptr;
			Node* current = __head;
			Node* next = current->next;

			while (next != nullptr) {
				if (current->data > next->data) {
					if (previous != nullptr) {
						previous->next = next;
					}
					else {
						__head = next;
					}

					current->next = next->next;
					next->next = current;

					previous = next;
					next = current->next;

					swapped = true;
				}
				else {
					previous = current;
					current = next;
					next = next->next;
				}
			}
		} while (swapped);

		displayList();
	}

};

int main()
{
	LinkedList list;
	
	list.addNode(31);
	list.addNode(11);
	list.addNode(15);
	list.addNode(105);
	list.addNode(26, 2);

	list.deleteNode();

	Node* node = list.searchNode(3);

	list.displayList();

	std::cout << "My value: " << node->data << std::endl;

	list.sortList();
	return 0;
}