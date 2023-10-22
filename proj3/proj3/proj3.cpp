#include <iostream>
#include "Header.h"

using namespace std;

template<typename Type>
Array<Type> createArray(int rows, int cols) {
    Type** arr = new Type * [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new Type[cols];
    }
    return arr;
}

int main()
{
    int rows = 4;
    int cols = 4;
    Array<int> array = createArray<int>(rows, cols);

	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			array.array[i][t] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		array.array[i][i] = 1;
	}
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			cout << '[' << array.array[i][t] << ']';
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			array.array[i][t] = 0;
		}
	}

	int t = 3;
	int* ptr = &t;

	for (int i = 0; i < 4; i++) {
		array.array[i][*ptr] = 1;
		*ptr -= 1;
	}

	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			cout << '[' << array.array[i][t] << ']';
		}
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			array.array[i][t] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		array.array[i][i] = 1;
	}
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			cout << '[' << array.array[i][t] << ']';
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			array.array[i][t] = 0;
		}
	}



	delete[] array.array;
}
