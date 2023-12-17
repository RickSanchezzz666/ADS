#include "BubbleSort.hpp"
#include <algorithm>

void bubbleSort(int arr[], int size) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 1; i < size - 1; i++) {
			if (arr[i - 1] > arr[i]) {
				std::swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
	} while (swapped);
}