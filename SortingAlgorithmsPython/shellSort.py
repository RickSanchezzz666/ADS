def shell_sort(arr):
    interval = len(arr) // 2
    while interval > 0:
        for i in range(interval, len(arr)):
            key = arr[i]
            j = i
            while j >= interval and arr[j - interval] > key:
                arr[j] = arr[j - interval]
                j -= interval 
            arr[j] = key
        interval //= 2