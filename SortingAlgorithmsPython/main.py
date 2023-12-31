import bubbleSort
import selectionSort
import insertionSort
import mergeSort
import quickSort
import countingSort
import radixSort

def displayArray(arr):
    for x in arr:
        print(f'{x} ', end='')
    print()

def sort(*args):
    print(f'{args[0]}: ' , end='')

    arr_to_sort = args[2].copy()

    if len(args) > 3: args[1](arr_to_sort, *args[3:])
    else: args[1](arr_to_sort)

    displayArray(arr_to_sort)


arr = [25, 8, 69, 52, 81, 97, 7, 67, 98, 68, 27, 56, 16, 20, 19]

#BubbleSort

sort('BubbleSort', bubbleSort.bubble_sort, arr)

#SelectionSort

sort('SelectionSort', selectionSort.selection_sort, arr)

#InsertionSort

sort('InsertionSort', insertionSort.insertion_sort, arr)

#MergeSort

sort('MergeSort', mergeSort.merge_sort, arr, 0, len(arr) - 1)

#QuickSort

sort('QuickSort', quickSort.quick_sort, arr, 0, len(arr) - 1)

#CountingSort

sort('CountingSort', countingSort.counting_sort, arr)

#RadixSort

sort('RadixSort', radixSort.radix_sort, [373, 128, 815, 588, 766, 708, 118, 848, 159, 464, 254, 348, 352])




