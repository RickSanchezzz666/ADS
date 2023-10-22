#include <iostream>

using namespace std;

void bubbleSort(int array[100], int arrLength) {
	int leftElem;
	int rightElem;
	for (int i = 1; i < arrLength; i++) {
		leftElem = array[i - 1];
		rightElem = array[i];
		if (leftElem > rightElem) {
			swap(array[i - 1], array[i]);
		}
	}
	for (int i = 1; i < arrLength; i++) {
		leftElem = array[i - 1];
		rightElem = array[i];
		if (leftElem > rightElem) {
			bubbleSort(array, arrLength);
		}
	}
}

void insertionSort(int array[100], int arrLength) {
	int key;
	int j;
	for (int i = 1; i < arrLength; i++) {
		key = array[i];
		j = i - 1;
		while (array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void selectionSort(int array[100], int arrLength) {
	int min;
	for (int i = 0; i < arrLength - 1; i++) {
		min = i;
		for (int j = i + 1; j < arrLength; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(array[min], array[i]);
		}
	}
}


//quickSort незміг сам зробить, взяв на гікфоргікс :)
int partition(int arr[], int start, int end)
{
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}

void display(int array[], int arrLength) {
	cout << "\nSorted array is: ";
	for (int i = 0; i < arrLength; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

int main() {
	int choice = 0;
	int arrLength = 0;
	int array[100];
	cout << "Enter the lenght of array(max: 100): ";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++) {
		cout << "Enter the " << i + 1 << " number: ";
		cin >> array[i];
	}
	for (int end = 0; end < 1;) {
		cout << "\nChoose the number.\n" << "1. Bubble Sort\n" << "2. Insertion Sort\n" << "3. Selection Sort\n" << "4. Quick Sort\n" << "5. Enter new array\n" << "6. Finish the program.\n" << "\nEnter the number: ";
		cin >> choice;
		switch (choice) {
		case 1:
			bubbleSort(array, arrLength);
			display(array, arrLength);
			break;
		case 2:
			insertionSort(array, arrLength);
			display(array, arrLength);
			break;
		case 3:
			selectionSort(array, arrLength);
			display(array, arrLength);
			break;
		case 4:
			quickSort(array, 0, arrLength - 1);
			display(array, arrLength);
			break;
		case 5:
			cout << "\nEnter the lenght of array(max: 100): ";
			cin >> arrLength;
			for (int i = 0; i < arrLength; i++) {
				cout << "Enter the " << i + 1 << " number: ";
				cin >> array[i];
			}
			break;
		case 6:
			cout << "\n\nYou finished the program!\n";
			end = 1;
			return 0;
		default:
			cout << "\n\nYou entered the wrong number!\n" << "Try again!\n";
			break;
		}
	}
}