def bubble_sort(arr, swapped = False):
    swapped = False
    for i in range(1, len(arr)):
        if arr[i - 1] > arr[i]:
            arr[i - 1], arr[i] = arr[i], arr[i - 1]
            swapped = True
    if swapped: bubble_sort(arr, swapped)
    else: return arr
    