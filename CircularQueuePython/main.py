class CircularQueue:
    def __init__(self, size):
        self.__size = size
        self.__elements = [None] * size
        self.__front = -1
        self.__rear = -1
    
    def __isEmpty(self):
        if self.__front == self.__rear == -1:
            print('\nYour Queue is Empty!')
            return True
        return False
    
    def __isFull(self):
        if (self.__front == 0 and self.__rear == self.__size - 1) or (self.__front == self.__rear + 1):
            print('\nYour Queue is Full!')
            return True
        return False
    
    def getPeek(self):
        if self.__isEmpty(): return
        peekElement = self.__elements[self.__front]
        print(f'\nYour peek element is: {peekElement}')
        return peekElement
    
    def enqueue(self, newItem):
        if self.__isFull(): return
        if self.__front == -1: self.__front = 0
        self.__rear = (self.__rear + 1) % self.__size
        self.__elements[self.__rear] = newItem

    def dequeue(self): 
        if self.__isEmpty(): return
        if self.__front == self.__rear:
            self.__front = -1
            self.__rear = -1
            self.__elements = [None] * self.__size
        else: self.__front = (self.__front + 1) % self.__size
        return self.__front
    
    def display(self):
        if self.__isEmpty(): return
        print('\nYour Circular Queue: ')
        if self.__rear >= self.__front:
            for i in range(self.__front, self.__rear + 1):
                print(f'[{self.__elements[i]}]', end='', flush=True)
        else:
            for i in range(self.__front, self.__size):
                print(f'[{self.__elements[i]}]', end='', flush=True)
            for i in range(self.__rear + 1):
                print(f'[{self.__elements[i]}]', end='', flush=True)

size = 5

q = CircularQueue(size)

q.enqueue(5)
q.enqueue(14)
q.enqueue(3)
q.enqueue(6)
q.enqueue(2)

q.display()
q.getPeek()

q.dequeue()
q.dequeue()

q.enqueue(13)
q.enqueue(56)
q.display()
q.getPeek()

q.dequeue()

q.display()
q.getPeek()

q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()

q.display()