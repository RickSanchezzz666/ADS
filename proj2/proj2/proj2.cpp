#include <iostream>

using namespace std;

int* create(int arrSize) {
    int* ptr = new int[arrSize];
    return ptr;
}

void intitalization(int* ptr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        ptr[i] = 0;
    }
}

void copyArray(int* array1, int* array2, int arrSize1) {
    copy(array1, array1 + arrSize1, array2);
}

void deleteArray(int* array) {
    delete[] array;
}

int* resizeArray(int* array, int* oldArraySize, int newSize) {
    int* tempArr = create(*oldArraySize);
    int tempSize = *oldArraySize;
    copy(array, array + *oldArraySize, tempArr);
    *oldArraySize = newSize;
    array = new int[newSize];
    intitalization(array, *oldArraySize);
    if (newSize < tempSize) {
        copy(tempArr, tempArr + newSize, array);
    }
    else {
        copy(tempArr, tempArr + tempSize, array);
    }
    deleteArray(tempArr);
    return array;
}

int main()
{
    int arrSize1 = 0;
    int* ptr1 = &arrSize1;
    cout << "Enter the size of the first array: ";
    cin >> arrSize1;
    int* dynArr1 =  create(arrSize1);
    intitalization(dynArr1, arrSize1);


    dynArr1[arrSize1 - 1] = 6;
    dynArr1[0] = 13;

    for (int i = 0; i < arrSize1; i++) {
        cout << dynArr1[i] << ' ';
    }
    cout << '\n';

    int arrSize2 = 0;
    int* ptr2 = &arrSize2;
    cout << "Enter the size of the second array: ";
    cin >> arrSize2;
    int* dynArr2 = create(arrSize2);
    intitalization(dynArr2, arrSize2);


    if (arrSize2 < arrSize1) {
        cout << "Can't copy array because it's too small!" << endl;
    }
    else {
        copyArray(dynArr1, dynArr2, arrSize1);
    }

    for (int i = 0; i < arrSize2; i++) {
        cout << dynArr2[i] << ' ';
    }
    cout << '\n';

    cout << "Enter new size of array: ";

    int newSize = 0;

    cin >> newSize;

    dynArr1 = resizeArray(dynArr1, ptr1, newSize);

    cout << "Resized array: " << endl;

    for (int i = 0; i < arrSize1; i++) {
        cout << dynArr1[i] << ' ';
    }
    cout << '\n';

    deleteArray(dynArr1);
    deleteArray(dynArr2);

}

// створення, видалення, копіювання, ініціалізація, зміна розміру
