#pragma once
#include <vector>

enum class HeapType {
	MaxHeap,
	MinHeap
};

class Heap {
private:
	std::vector<int> __array;

	HeapType __hType;

	void __swap(int* a, int* b);

	void __heapify(int i);
public:
	Heap(HeapType hType);

	void insertInHeap(int newData);

	void deleteFromHeap(int data);

	int getPeek();

	void extractPeek();

	void displayHeap();
};
