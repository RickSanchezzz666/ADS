#include "Heap.hpp"
#include <iostream>

int main() {
	Heap heap(HeapType::MinHeap);

	heap.insertInHeap(3);
	heap.insertInHeap(10);
	heap.insertInHeap(41);
	heap.insertInHeap(66);
	heap.insertInHeap(6);
	heap.insertInHeap(11);

	heap.deleteFromHeap(41);

	heap.extractPeek();

	heap.displayHeap();

	return 0;
}