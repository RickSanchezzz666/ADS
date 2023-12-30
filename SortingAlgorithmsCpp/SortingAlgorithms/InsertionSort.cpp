#include "InsertionSort.hpp"

void insertionSort(int arr[], int size) {
	int i = 1;
	for (int step = 1; step < size; step++) {
		i = step;
		int key = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (key < arr[j]) {
				arr[i] = arr[j];
				arr[j] = key;
				i--;
			} else { break; }
		}
	}
}
