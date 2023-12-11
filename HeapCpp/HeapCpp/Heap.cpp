#include "Heap.hpp"
#include <iostream>
#include <vector>

Heap::Heap(HeapType type) { 
	__hType = type;
}

void Heap::__swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Heap::__heapify(int i) {
	if (__hType == HeapType::MaxHeap) {
		int largest = i;
		int size = __array.size();

		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < size && __array[l] > __array[largest]) {
			largest = l;
		}
		if (r < size && __array[r] > __array[largest]) {
			largest = r;
		}

		if (largest != i) {
			__swap(&__array[i], &__array[largest]);
			__heapify(largest);
		}
	}
	else if (__hType == HeapType::MinHeap) {
		int smallest = i;
		int size = __array.size();

		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < size && __array[l] < __array[smallest]) {
			smallest = l;
		}
		if (r < size && __array[r] < __array[smallest]) {
			smallest = r;
		}

		if (smallest != i) {
			__swap(&__array[i], &__array[smallest]);
			__heapify(smallest);
		}
	}
}

void Heap::insertInHeap(int newData) {
	int size = __array.size();
	if (size == 0) {
		__array.push_back(newData);
		return;
	}
	else {
		__array.push_back(newData);
		for (int i = size / 2 - 1; i >= 0; --i) {
			__heapify(i);
		}
		return;
	}
}

void Heap::deleteFromHeap(int data) {
	int size = __array.size();
	int i;
	bool found = false;
	for (i = 0; i < size; i++) {
		if (data == __array[i]) { 
			found = true;
			break; 
		}
	}
	if (found) {
		__swap(&__array[i], &__array[size - 1]);
		__array.pop_back();
		size = __array.size();
		for (int i = size / 2 - 1; i >= 0; --i) {
			__heapify(i);
		}
		return;
	}
	else {
		std::cout << "You entered invalid number to delete!\n";
	}
}

int Heap::getPeek() {
	return __array[0];
}

void Heap::extractPeek() {
	int peek = getPeek();
	deleteFromHeap(peek);
	std::cout << "You successfully extracted peek element: " << peek << "!\n";
	int size = __array.size();
	for (int i = size / 2 - 1; i >= 0; --i) {
		__heapify(i);
	}
}

void Heap::displayHeap() {
	for (auto x : __array) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
