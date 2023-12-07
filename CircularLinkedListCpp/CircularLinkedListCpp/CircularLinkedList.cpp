#include <iostream>

#include "CircularLinkedList.hpp"

#define SIZE 5

bool CircularLinkedList::__isListEmpty() {
	return (__head == nullptr);
}

bool CircularLinkedList::__isListFull() {
	return (__count == SIZE - 1);
}

CircularLinkedList::CircularLinkedList() { __head = new Node; }

CircularLinkedList::~CircularLinkedList() {
	Node* node = __head;
	Node* next = nullptr;
	for (int i = 0; i < __count; i++) {
		next = node->next;
		delete node;
		node = next;
	}

	__head = nullptr;
}

void CircularLinkedList::insertionAtTheBeggining(int newData) {
	if (__isListFull()) {
		std::cout << "Your List is Full!" << std::endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = __head;

	Node* node = __head;

	for (int i = 0; i < __count; i++) {
		node = node->next;
	}

	node->next = newNode;

	__head = newNode;

	++__count;
}

void CircularLinkedList::insertionAtTheEnd(int newData) {
	if (__isListFull()) {
		std::cout << "Your List is Full!" << std::endl;
		return;
	}
	else if (__isListEmpty()) {
		insertionAtTheBeggining(newData);
		return;
	}
	else {
		Node* newNode = new Node;
		newNode->data = newData;

		Node* node = __head;

		for (int i = 0; i < __count; i++) {
			node = node->next;
		}
		newNode->next = __head;

		node->next = newNode;

		++__count;
	}
}

void CircularLinkedList::insertionAfterNode(int newData, int nodePos) {
	if (__isListFull()) {
		std::cout << "Your List is Full!" << std::endl;
		return;
	}
	else if (nodePos < 1) {
		insertionAtTheBeggining(newData);
		return;
	}
	else if (nodePos - 1 >= __count) {
		insertionAtTheEnd(newData);
		return;
	}
	else {
		Node* newNode = new Node;
		newNode->data = newData;

		Node* node = __head;

		for (int i = 0; i < nodePos - 1; i++) {
			node = node->next;
		}

		newNode->next = node->next;
		node->next = newNode;

		++__count;
	}

}

void CircularLinkedList::deleteAtTheBeggining() {
	if (__isListEmpty()) {
		std::cout << "Your List is Empty!" << std::endl;
		return;
	}

	Node* node = __head;
	__head = __head->next;

	delete node;

	--__count;
}

void CircularLinkedList::deleteAtTheEnd() {
	if (__isListEmpty()) {
		std::cout << "Your List is Empty!" << std::endl;
		return;
	}
	else if (__count == 0) {
		Node* node = __head;
		delete node;
		__head = nullptr;
		--__count;
	}
	else {
		Node* node = __head;

		for (int i = 0; i < __count - 1; i++) {
			node = node->next;
		}

		delete node->next;
		node->next = __head;

		--__count;
	}

}

void CircularLinkedList::deleteNode(int nodePos) {
	if (__isListEmpty()) {
		std::cout << "Your List is Empty!" << std::endl;
		return;
	} else if (nodePos == 0) {
		deleteAtTheBeggining();
		return;
	}
	else if (nodePos - 1 >= __count && nodePos <= SIZE) {
		deleteAtTheEnd();
		return;
	}
	else if (nodePos > 0 && nodePos < SIZE) {
		Node* node = __head;
		Node* prev = nullptr;

		for (int i = 0; i < nodePos - 1; i++) {
			prev = node;
			node = node->next;
		}

		if (prev != nullptr) {
			prev->next = node->next;
			delete node;
		}
		else {
			delete __head;
			__head = nullptr;
		}

		--__count;

	}
	else {
		std::cout << "\nInvalid Node Position to delete!\n";
		return;
	}
}

bool CircularLinkedList::searchNode(int data) {
	if (__isListEmpty()) {
		std::cout << "Your List is Empty!" << std::endl;
		return false;
	}

	Node* node = __head;

	for (int i = 0; i <= __count; i++) {
		if (node->data == data) {
			return true;
		}
		node = node->next;
	}

	return false;
}

void CircularLinkedList::displayList() {
	if (__isListEmpty()) {
		std::cout << "Your List is Empty!" << std::endl;
		return;
	}

	Node* node = __head;
	std::cout << "Your List is: " << __head->data;

	node = node->next;

	for (int i = 0; i < __count; i++) {
		std::cout << "->" << node->data;
		node = node->next;
	}

	std::cout << std::endl;
}