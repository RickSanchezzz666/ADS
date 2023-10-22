#pragma once
template<typename Type>
struct Array {
    Type** array;
    int row;
    int cols;
};