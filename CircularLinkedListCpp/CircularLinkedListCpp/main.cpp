#include <iostream>

#include "CircularLinkedList.hpp"

int main() {
	CircularLinkedList list;

	list.insertionAtTheBeggining(5);
	list.insertionAtTheBeggining(13);
	list.insertionAtTheEnd(14);
	list.insertionAfterNode(66, 2);
	list.insertionAtTheEnd(32);

	list.deleteAtTheBeggining();
	list.deleteAtTheEnd();

	list.deleteNode(2);

	list.displayList();

	bool node = list.searchNode(14);

	std::cout << "My node found: " << (node ? "true" : "false") << std::endl;


	return 0;
};