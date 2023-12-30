def merge_arrays(arr, p, q, r):
    size1 = q - p + 1
    size2 = r - q

    l = arr[p:p + size1].copy()
    m = arr[q + 1:q + 1 + size2].copy()

    i = j = 0
    k = p

    while ((i < size1) and (j < size2)):
        if l[i] <= m[j]:
            arr[k] = l[i]
            i += 1
        else:
            arr[k] = m[j]
            j += 1
        k += 1

    while i < size1:
        arr[k] = l[i]
        i += 1
        k += 1

    while j < size2:
        arr[k] = m[j]
        j += 1
        k += 1


def merge_sort(arr, p, r):
    if p < r:
        q = p + (r - p) // 2

        merge_sort(arr, p, q)
        merge_sort(arr, q + 1, r)

        merge_arrays(arr, p, q, r)