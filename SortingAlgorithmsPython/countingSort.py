def counting_sort(arr):
    max_val = max(arr)

    count = [0] * (max_val + 1)
    final_array = [None] * len(arr)

    for i in range(len(arr)): count[arr[i]] += 1

    for i in range(1, max_val + 1): count[i] += count[i - 1]

    j = len(arr) - 1
    while j >= 0:
        final_array[count[arr[j]] - 1] = arr[j]
        count[arr[j]] -= 1
        j -= 1

    for i in range(len(arr)): arr[i] = final_array[i]