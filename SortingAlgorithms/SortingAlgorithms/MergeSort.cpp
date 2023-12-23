#include "MergeSort.hpp"

void mergeArrays(int arr[], int p, int q, int r) {
	int size1 = q - p + 1;
	int size2 = r - q;

	int* L = new int[size1];
	int* M = new int[size2];

	for (int i = 0; i < size1; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < size2; j++) {
		M[j] = arr[q + 1 + j];
	}

	int i = 0, j = 0, k = p;

	while (i < size1 && j < size2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	while (i < size1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < size2) {
		arr[k] = M[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] M;
}

void mergeSort(int arr[], int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;

		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);

		mergeArrays(arr, p, q, r);
	}
}