#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"

static void displayArray(int arr[], int size) {
	for (int i = 0; i < size; i++ ) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	int size = sizeof(arr) / sizeof(int);

	std::cout << "Your array is: ";

	displayArray(arr, size);

	std::cout << "-----------------------------------------------\n";


	// BubbleSort

	int bubble[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "BubbleSort: ";

	bubbleSort(bubble, size);

	displayArray(bubble, size);


	// SelectionSort

	int selection[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nSelectionSort: ";

	selectionSort(selection, size);

	displayArray(selection, size);


	//InsertionSort

	int insertion[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nInsertionSort: ";

	insertionSort(insertion, size);

	displayArray(insertion, size);


	//MergeSort

	int merge[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nMergeSort: ";

	int p = 0;

	int r = size - 1;

	mergeSort(merge, p, r);

	displayArray(merge, size);


	return 0;
}