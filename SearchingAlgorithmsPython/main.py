def linear_search(arr, target):
    for x in arr: 
        if x == target: return x
    return -1

def binary_search_recursive(arr, target, low, high):
    if (high >= low):
        mid = low + (high - low) // 2

        if (arr[mid] == target):
            return mid
        
        elif (target > arr[mid]):
            return binary_search_recursive(arr, target, mid + 1, high)
        
        else:
            return binary_search_recursive(arr, target, low, mid - 1)
    return -1

def binary_search_iterative(arr, target, low, high):
    while (low <= high):
        mid = low + (high - low) // 2

        if (arr[mid] == target):
            return mid
        
        elif (target > arr[mid]):
            low = mid - 1
        
        else:
            high = mid - 1
    return -1

arr = [ 3, 47, 80, 23, 53, 12, 67, 6, 34, 25, 81, 82, 93, 87, 37, 19, 6, 61, 78, 3, 28, 17, 31, 22, 54 ]

#LinearSearch

linear_result = linear_search(arr, 34)

print(f'Linear search position: {linear_result if linear_result != -1 else 'Not found!'}')

#BinarySearch

import bubbleSort

bubbleSort.bubbleSort(arr)

binary_result_recursive = binary_search_recursive(arr, 25, 0, len(arr) - 1)

print(f'Binary recursive position: {binary_result_recursive if binary_result_recursive != -1 else 'Not found!'}')

binary_result_iterative = binary_search_iterative(arr, 61, 0, len(arr) - 1)

print(f'Binary iterative position: {binary_result_iterative if binary_result_iterative != -1 else 'Not found!'}')