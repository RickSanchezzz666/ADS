#include <iostream>
#include <string>

#include "QuickSort.hpp"

int linearSearch(int arr[], int, int);
int binarySearchRecursive(int arr[], int, int, int);
int binarySearchIterative(int arr[], int, int, int);

int main() {
	int arr[] = { 3, 47, 80, 23, 53, 12, 67, 6, 34, 25, 81, 82, 93, 87, 37, 19, 6, 61, 78, 3, 28, 17, 31, 22, 54 };

	int size = sizeof(arr) / sizeof(arr[0]);


	//LinearSearch

	int result = linearSearch(arr, size, 6);

	std::cout << (result != -1 ? "The result position of linear is: " + std::to_string(result) + "\n" : "Not found!\n");

	result = linearSearch(arr, size, 66);

	std::cout << (result != -1 ? "The result position of linear is: " + std::to_string(result) + "\n" : "Not found!\n");


	//BinarySearch

	quickSort(arr, 0, size - 1);

	int resPosition = binarySearchRecursive(arr, 0, size - 1, 19);

	std::cout << (resPosition != -1 ? "The result position of binary recursive is: " + std::to_string(resPosition) + "\n" : "Not found!\n");

	resPosition = binarySearchIterative(arr, 0, size - 1, 93);

	std::cout << (resPosition != -1 ? "The result position of binary iterativea is: " + std::to_string(resPosition) + "\n" : "Not found!\n");

}

int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (target == arr[i]) { return i; }
	}
	return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target) {
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			return binarySearchRecursive(arr, low, mid - 1, target);
		}
		else {
			return binarySearchRecursive(arr, mid + 1, high, target);
		}
	}

	return -1;
}

int binarySearchIterative(int arr[], int low, int high, int target) {
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		else if (arr[mid] > target) {
			high = mid - 1;
		}

		else {
			low = mid + 1;
		}
	}

	return -1;
}