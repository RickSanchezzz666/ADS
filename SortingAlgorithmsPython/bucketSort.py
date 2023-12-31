import bubbleSort

def get_bucket_index(val, bucket_capacity):
    return int(val * bucket_capacity)

def bucket_sort(arr, buckets_num, bucket_capacity):
    buckets = [[] for _ in range(buckets_num)]

    for i in range(len(arr)):
        index = get_bucket_index(arr[i], bucket_capacity)
        buckets[index].append(arr[i])

    for i in range(buckets_num):
        if buckets[i] != None: bubbleSort.bubble_sort(buckets[i])

    j = 0
    for i in range(buckets_num):
        if buckets[i] != None:
            for x in buckets[i]:
                arr[j] = x
                j += 1