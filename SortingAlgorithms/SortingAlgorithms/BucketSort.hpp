#pragma once
#include <vector>

static int getBucketIndex(float val, int bucketCap);
void bubbleSortModified(std::vector<float>& arr, int size);
void bucketSort(float arr[], int size, int bucketsNum, int bucketCap);