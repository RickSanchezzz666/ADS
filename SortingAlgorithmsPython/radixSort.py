def modified_counting_sort(arr, place):
    max_val = max(arr)

    count = [0] * (max_val + 1)
    final_array = [None] * len(arr)

    for i in range(len(arr)): count[(arr[i] // place) % 10] += 1

    for i in range(1, max_val + 1): count[i] += count[i - 1]

    j = len(arr) - 1
    while j >= 0:
        final_array[count[(arr[j] // place) % 10] - 1] = arr[j]
        count[(arr[j] // place) % 10] -= 1
        j -= 1

    for i in range(len(arr)): arr[i] = final_array[i]


def radix_sort(arr):
    max_val = max(arr)

    place = 1
    while max_val // place > 0:
        modified_counting_sort(arr, place)
        place *= 10