#pragma once

struct Node {
	int data = 0;
	struct Node* next = nullptr;
};

class CircularLinkedList {
private:
	int __count = -1;
	Node* __head;

	bool __isListEmpty();

	bool __isListFull();

public:
	CircularLinkedList();

	void insertionAtTheBeggining(int newData);

	void insertionAtTheEnd(int newData);

	void insertionAfterNode(int newData, int nodePos);

	void deleteAtTheBeggining();

	void deleteAtTheEnd();

	void deleteNode(int nodePos);

	bool searchNode(int data);

	void displayList();

	~CircularLinkedList();
};