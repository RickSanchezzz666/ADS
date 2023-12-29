#include "BucketSort.hpp"
#include <vector>


static int getBucketIndex(float val, int bucketCap) {
	return val * bucketCap;
}

static void bubbleSortModified(std::vector<float>& arr, int size) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 1; i <= size; i++) {
			if (arr[i - 1] > arr[i]) {
				std::swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
	} while (swapped);
}

void bucketSort(float arr[], int size, int bucketsNum , int bucketCap) {
	bucketsNum = size;

	std::vector<std::vector<float>> buckets(bucketsNum);

	for (int i = 0; i < size; i++) {
		int index = getBucketIndex(arr[i], bucketCap);
		buckets[index].push_back(arr[i]);
	}

	for (int i = 0; i < bucketsNum; i++) {
		if (buckets[i].size() != 0) bubbleSortModified(buckets[i], buckets[i].size() - 1);
	}

	int j = 0;

	for (int i = 0; i < bucketsNum; i++) {
		if (buckets[i].size() != 0) {
			for (auto x : buckets[i]) {
				arr[j] = x;
				j++;
			}
		}
	}
}