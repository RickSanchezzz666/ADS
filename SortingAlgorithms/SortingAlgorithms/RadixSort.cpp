#include "RadixSort.hpp"

void modifiedCountingSort(int arr[], int size, int place) {
	int max = arr[0];
	for (int i = 1; i < size; i++) if (max < arr[i]) max = arr[i];

	int* count = new int[max + 1]();
	int* finalArr = new int[size];

	for (int i = 0; i < size; i++) count[(arr[i] / place) % 10]++;

	for (int i = 1; i <= max; i++) count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--) {
		finalArr[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++) arr[i] = finalArr[i];

	delete[] count;
	delete[] finalArr;

}

void radixSort(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) if (max < arr[i]) max = arr[i];

	for (int place = 1; max / place > 0; place *= 10) {
		modifiedCountingSort(arr, size, place);
	}
}