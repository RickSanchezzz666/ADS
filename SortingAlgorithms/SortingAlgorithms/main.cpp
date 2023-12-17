#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"

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

	std::cout << "BubbleSort: ";

	bubbleSort(arr, size);

	displayArray(arr, size);


	// SelectionSort

	std::cout << "\nSelectionSort: ";

	selectionSort(arr, size);

	displayArray(arr, size);




	return 0;
}