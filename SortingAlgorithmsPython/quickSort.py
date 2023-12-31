def partition(arr, f, l):
    pivot = arr[l]

    i = f - 1

    for j in range(f, l):
        if arr[j] <= pivot:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]

    arr[i + 1], arr[l] = arr[l], arr[i + 1]

    return i + 1


def quick_sort(arr, f, l):
    if f < l:
        pivot = partition(arr, f, l)
        quick_sort(arr, f, pivot - 1)
        quick_sort(arr, pivot, l)