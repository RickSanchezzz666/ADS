class Queue:
    def __init__(self):
        self.__queue = list()
        self.__front = -1
        self.__rear = -1

    def __isEmpty(self):
        if self.__front == -1 and self.__rear == -1:
            print('\nThe queue is empty!')
            return True
        else: return False

    def getPeek(self):
        if self.__isEmpty(): return
        peekElement = self.__queue[self.__front]
        print(f'\nYour peek element is: {peekElement}')
        return peekElement
    
    def enqueue(self, newItem):
        if self.__front == -1 and self.__rear == -1: self.__front = 0
        self.__rear += 1
        self.__queue.append(newItem)

    def dequeue(self):
        if self.__isEmpty(): return
        self.__front += 1
        if self.__front > self.__rear:
            self.__init__()
        return self.__front
    
    def printQueue(self):
        if self.__isEmpty(): return
        print('\nThe queue is: ')
        for i in range(self.__front, len(self.__queue)):
            print(f'[{self.__queue[i]}]', end='', flush=True)
    
q = Queue()

q.enqueue(3)
q.enqueue(6)
q.enqueue(523)
q.enqueue(5)
q.enqueue(21)

q.printQueue()
q.getPeek()

q.dequeue()
q.dequeue()

q.enqueue(52)

q.printQueue()
q.getPeek()