import Heap

heap = Heap.Heap(Heap.HeapType.MAX_HEAP)

heap.insert_into_heap(13)
heap.insert_into_heap(41)
heap.insert_into_heap(62)
heap.insert_into_heap(5)
heap.insert_into_heap(9)
heap.insert_into_heap(31)

heap.display_heap()

heap.extract_peek()

heap.display_heap()