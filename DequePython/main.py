class Deque:
    def __init__(self):
        self.__array = []

    def __isEmpty(self):
        return self.__array == []
    
    def pushFront(self, newItem):
        self.__array.insert(0, newItem)

    def pushRear(self, newItem):
        self.__array.append(newItem)

    def popFront(self):
        if not self.__isEmpty():
            self.__array.pop(0)

    def popRear(self):
        if not self.__isEmpty():
            self.__array.pop()

    def displayDeque(self):
        for elem in self.__array:
            print(f'[{elem}]', end='')
        print('\n')


dq = Deque()

dq.pushFront(4)
dq.pushFront(6)
dq.pushRear(13)

dq.displayDeque()

dq.pushFront(5)
dq.popRear()
dq.pushRear(12)

dq.displayDeque()