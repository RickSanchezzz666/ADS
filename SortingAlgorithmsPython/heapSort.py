def heapify(arr, size, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < size and arr[l] > arr[largest]:
        largest = l

    if r < size and arr[r] > arr[largest]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, size, largest)

def heap_sort(arr):
    for i in range(len(arr) // 2 - 1, -1, -1):
        heapify(arr, len(arr), i)

    for i in range(len(arr) - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)