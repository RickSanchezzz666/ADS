def insertion_sort(arr):
    i = 1
    for step in range(1, len(arr)):
        i = step
        key = arr[i]
        for j in range(i - 1, -1, -1):
            if key < arr[j]:
                arr[i] = arr[j]
                arr[j] = key
                i -= 1
            else: break