class LinkedList:
    class Node:
        def __init__(self, data = None):
            self.data = data
            self.next = None

    def __init__(self, size):
        self.__size = size
        self.__count = 0
        self.__head = self.Node()

    def __isListEmpty(self):
        if self.__count == 0 and self.__head.next == None: return True
        else: return False

    def __isListFull(self):
        if self.__count == self.__size: return True
        else: return False

    def addNode(self, newData, nodePos = -1):
        if self.__isListFull(): return print('The List is Full!\n')
        else:   
            if nodePos == -1:
                newNode = self.Node(data=newData)
                node = self.__head
                while node.next is not None:
                    node = node.next
                node.next = newNode
                node.data = newData
                self.__count += 1
            else:
                if nodePos > self.__count or nodePos < 1:
                    print("Node doesn't found!")
                    return
                else:
                    newNode = self.Node(data=newData)
                    node = self.__head
                    for _ in range(1, nodePos):
                        node = node.next
                    newNode.next = node.next
                    node.next = newNode
                    self.__count += 1

    def deleteNode(self):
        if self.__isListEmpty(): return print('The List is Empty!\n')
        else:
            prev = None
            node = self.__head
            while node.next is not None:
                prev = node
                node = node.next

            prev.next = None
            self.__count -= 1

    def searchNode(self, nodePos):
        if self.__isListEmpty(): return print('The List is Empty!\n')
        else:
            if nodePos > self.__count or nodePos < 1:
                print("Node doesn't found!")
                return
            else:
                node = self.__head
                for _ in range(1, nodePos):
                    node = node.next
                return node

    def sortList(self):
        if self.__isListEmpty():
            print("The List is Empty!\n")
            return

        swapped = True
        while swapped:
            swapped = False
            previous = None
            current = self.__head
            next_node = current.next

            while next_node is not None:
                if current.data > next_node.data:
                    if previous is not None:
                        previous.next = next_node
                    else:
                        self.__head = next_node

                    current.next = next_node.next
                    next_node.next = current

                    previous = next_node
                    next_node = current.next

                    swapped = True
                else:
                    previous = current
                    current = next_node
                    next_node = next_node.next

        self.displayList()


    def displayList(self):
        if self.__isListEmpty(): return print('The List is Empty!\n')
        else:
            node = self.__head
            print('\nYour list is:\nHEAD', end='')
            while (node.next != None):
                print(f'->{node.data}', end='')
                node = node.next

                


list = LinkedList(5)

list.addNode(2)
list.addNode(10)
list.addNode(31)
list.addNode(50)

list.addNode(125, 2)

list.deleteNode()

node = list.searchNode(3)

print(node.data)

list.displayList()

list.sortList()
