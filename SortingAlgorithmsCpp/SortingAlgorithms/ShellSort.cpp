#include "ShellSort.hpp"

void shellSort(int arr[], int size) {
	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i++) {
			int key = arr[i];
			int j;
			for (j = i; j >= interval && arr[j - interval] > key; j -= interval) {
				arr[j] = arr[j - interval];
			}
			arr[j] = key;
		}
	}
}