class PrirityQueue:
    def __init__(self):
        self.__queue = []

    def __isQueueIsEmpty(self):
        return self.__queue == []
    
    def pushInQueue(self, newData):
        if self.__isQueueIsEmpty():
            self.__queue.append(newData)
        else:
            for i in range(len(self.__queue)):
                if newData <= self.__queue[i]:
                    self.__queue.insert(i, newData)
                    return
            self.__queue.append(newData)
            return
        
    def popFromQueue(self):
        if self.__isQueueIsEmpty():
            print('Your Queue is Empty!\n')
            return
        
        return self.__queue.pop()
    
    def getPeek(self):
        if self.__isQueueIsEmpty():
            print('Your Queue is Empty!\n')
            return
        
        return self.__queue[len(self.__queue) - 1]
    

    def searchNode(self, data):
        if self.__isQueueIsEmpty():
            print('Your Queue is Empty!\n')
            return
        
        for i in range(len(self.__queue)):
            if data == self.__queue[i]:
                return True
        return False
    
        
    def displayQueue(self):
        if self.__isQueueIsEmpty():
            print('Your Queue is Empty!\n')
            return
        
        print('Your queue is: ', end='')
        for num in self.__queue:
            print(f'{num} ', end='')
        print('\n')


queue = PrirityQueue()

queue.pushInQueue(10)
queue.pushInQueue(12)
queue.pushInQueue(5)
queue.pushInQueue(15)

queue.popFromQueue()

queue.getPeek()

elem = queue.searchNode(10)

print(elem if elem else not elem)

queue.displayQueue()