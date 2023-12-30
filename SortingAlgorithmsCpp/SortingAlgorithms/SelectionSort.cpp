#include "SelectionSort.hpp"
#include <algorithm>

void selectionSort(int arr[], int size) {
	for (int step = 0; step < size; step++) {
		int min = step;
		for (int i = step + 1; i < size; i++) {
			if (arr[min] > arr[i]) {
				min = i;
			}
		}
		std::swap(arr[step], arr[min]);
	}
}