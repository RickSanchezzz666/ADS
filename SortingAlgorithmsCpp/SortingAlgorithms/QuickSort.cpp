#include "QuickSort.hpp"
#include <iostream>

int partition(int arr[], int f, int l) {
	int pivot = arr[l];

	int i = f - 1;

	for (int j = f; j < l; j++) {
		if (arr[j] <= pivot) {
			i++;
			std::swap(arr[j], arr[i]);
		}
	}
	std::swap(arr[i + 1], arr[l]);

	return i + 1;
}

void quickSort(int arr[], int f, int l) {
	if (f < l) {
		int pivot = partition(arr, f, l);
		quickSort(arr, f, pivot - 1);
		quickSort(arr, pivot, l);
	}
}