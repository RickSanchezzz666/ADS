import bubbleSort
import selectionSort
import insertionSort
import mergeSort

def displayArray(arr):
    for x in arr:
        print(f'{x} ', end='')
    print()

def sort(*args):
    print(f'{args[0]}: ' , end='')

    arr_to_sort = arr.copy()

    if len(args) > 2: args[1](arr_to_sort, *args[2:])
    else: args[1](arr_to_sort)

    displayArray(arr_to_sort)


arr = [25, 8, 69, 52, 81, 97, 7, 67, 98, 68, 27, 56, 16, 20, 19]

#BubbleSort

sort('BubbleSort', bubbleSort.bubble_sort)

#SelectionSort

sort('SelectionSort', selectionSort.selection_sort)

#InsertionSort

sort('InsertionSort', insertionSort.insertion_sort)

#MergeSort

sort('MergeSort', mergeSort.merge_sort, 0, len(arr) - 1)




