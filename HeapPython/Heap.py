from enum import Enum

class HeapType(Enum):
    MAX_HEAP = 'MAX_HEAP',
    MIN_HEAP = 'MIN_HEAP'

class Heap:
    def __init__(self, htype: HeapType):
        self.__htype = htype
        self.__array = []

    def __swap(self, i, j):
        self.__array[i], self.__array[j] = self.__array[j], self.__array[i]

    def __heapify(self, i):
        if self.__htype == HeapType.MAX_HEAP:
            largest = i
            size = len(self.__array)
            l = 2 * i + 1
            r = 2 * i + 2

            if l < size and self.__array[l] > self.__array[largest]:
                largest = l
            if r < size and self.__array[r] > self.__array[largest]:
                largest = r
        
            if largest != i:
                self.__swap(i , largest)
                self.__heapify(largest)

        elif self.__htype == HeapType.MIN_HEAP:
            smallest = i
            size = len(self.__array)
            l = 2 * i + 1
            r = 2 * i + 2

            if l < size and self.__array[l] < self.__array[smallest]:
                smallest = l
            if r < size and self.__array[r] < self.__array[smallest]:
                smallest = r
        
            if smallest != i:
                self.__swap(i , smallest)
                self.__heapify(smallest)

    def insert_into_heap(self, newData):
        size = len(self.__array)
        if size == 0:
            self.__array.append(newData)
            return
        else:
            self.__array.append(newData)
            for i in range(size // 2 - 1, -1, -1):
                self.__heapify(i)
            return
        
    def delete_from_heap(self, data):
        size = len(self.__array)
        i = -1
        for j in range(size):
            if data == self.__array[j]:
                i = j
                break
        if i != -1:
            size = size - 1
            self.__swap(i, size)
            self.__array.pop()
            for i in range(size // 2 - 1, -1, -1):
                self.__heapify(i)
            return
        else:
            print("You entered invalid number to delete!\n")

    def get_peek(self):
        return self.__array[0]
    
    def extract_peek(self):
        peek = self.get_peek()
        self.delete_from_heap(peek)
        print(f"You successfully extracted peek element: {peek}!\n")
        size = len(self.__array)
        for i in range(size // 2 - 1, -1, -1):
                self.__heapify(i)

    def display_heap(self):
        for elem in self.__array:
            print(f'{elem} ', end='')
        print('\n')