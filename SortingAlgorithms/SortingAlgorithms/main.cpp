#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "CountingSort.hpp"
#include "RadixSort.hpp"
#include "BucketSort.hpp"
#include "HeapSort.hpp"
#include "ShellSort.hpp"

template <typename T>
static void displayArray(T arr[], int size) {
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

	mergeSort(merge, 0, size - 1);

	displayArray(merge, size);


	//QuickSort

	int quick[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nQuickSort: ";

	quickSort(quick, 0, size - 1);

	displayArray(quick, size);


	//CountingSort

	int counting[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nCountingSort: ";

	countingSort(counting, size);

	displayArray(counting, size);


	//RadixSort

	int radix[] = { 373, 128, 815, 588, 766, 708, 118, 848, 159, 464, 254, 348, 352 };

	int radixSize = sizeof(radix) / sizeof(int);

	std::cout << "\nRadixSort: ";

	radixSort(radix, radixSize);

	displayArray(radix, radixSize);


	//BucketSort

	float bucket[] = { .42, .35, .33, .52, .37, .47, .51 };

	int bucketSize = sizeof(bucket) / sizeof(int);

	std::cout << "\nBucketSort: ";

	bucketSort(bucket, bucketSize, bucketSize, 10);

	displayArray(bucket, bucketSize);


	//HeapSort

	int heap[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nHeapSort: ";

	heapSort(heap, size);

	displayArray(heap, size);


	//ShellSort

	int shell[] = { 16, 19, 20, 7, 1, 21, 10, 14, 5, 23, 6, 25 };

	std::cout << "\nShellSort: ";

	shellSort(shell, size);

	displayArray(shell, size);

	return 0;
}