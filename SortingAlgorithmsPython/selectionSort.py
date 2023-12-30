def selection_sort(arr):
    for step in range(len(arr)):
        min = step
        for i in range(step + 1, len(arr)):
            if arr[min] > arr[i]: min = i
        arr[step], arr[min] = arr[min], arr[step]