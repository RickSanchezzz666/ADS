class CircularLinkedList:
    class Node:
        def __init__(self, data = None):
            self.data = data
            self.next = None

    def __init__(self, size):
        self.__size = size
        self.__count = -1
        self.__head = self.Node()

    def __is_list_empty(self):
        return self.__count == -1

    def __is_list_full(self):
        return self.__count == self.__size - 1
    
    def insertion_at_the_beginning(self, newData):
        if self.__is_list_full():
            print("Your List is Full\n")
            return

        newNode = self.Node(newData)

        newNode.next = self.__head

        node = self.__head

        for _ in range(self.__count):
            node = node.next

        node.next = newNode

        self.__head = newNode

        self.__count += 1        


    def insertion_at_the_end(self, newData):
        if self.__is_list_full():
            print("Your List is Full\n")
            return
        elif self.__is_list_empty():
            self.insertion_at_the_beginning(newData)
            return
        
        newNode = self.Node(newData)

        node = self.__head

        for _ in range(self.__count):
            node = node.next

        newNode.next = self.__head

        node.next = newNode

        self.__count += 1    

    def insertion_after_node(self, newData, nodePos):
        if self.__is_list_full():
            print("Your List is Full\n")
            return
        elif nodePos < 1:
            self.insertion_at_the_beginning(newData)
            return
        elif nodePos - 1 >= self.__count:
            self.insertion_at_the_end(newData)
            return
        else:
            newNode = self.Node(newData)

            node = self.__head

            for _ in range(nodePos - 1):
                node = node.next

            newNode.next = node.next
            node.next = newNode

            self.__count += 1

    def delete_at_the_beginning(self):
        if self.__is_list_empty(): 
            print("Your List is Empty!\n")
            return

        self.__head = self.__head.next

        self.__count -= 1     
    
    def delete_at_the_end(self):
        if self.__is_list_empty(): 
            print("Your List is Empty!\n")
            return
        
        node = self.__head

        for _ in range(self.__count - 1):
            node = node.next

        node.next = self.__head

        self.__count -= 1

    def delete_node(self, nodePos):
        if self.__is_list_empty(): 
            print("Your List is Empty!\n")
            return
        elif nodePos == 0:
            self.delete_at_the_beginning()
            return
        elif nodePos - 1 >= self.__count and nodePos <= self.__size:
            self.delete_at_the_end()
            return
        elif nodePos > 0 and nodePos - 1 < self.__count:
            node = self.__head
            prev = None

            for _ in range(nodePos):
                prev = node
                node = node.next

            if prev != None:
                prev.next = node.next
            else:
                self.__head = None

            self.__count -= 1
        else:
            print('Invalid position to delete!\n')
            return

    def search_node(self, value):
        if self.__is_list_empty(): 
            print("Your List is Empty!\n")
            return
        
        node = self.__head

        for _ in range(self.__count):
            if node.data == value: return True
            else: node = node.next

        return True
        


    def display_list(self):
        if self.__is_list_empty(): 
            print("Your List is Empty!\n")
            return
    
        node = self.__head
        print(f"Your List is: {node.data}", end='')

        node = node.next
        for _ in range(self.__count):
            print(f'->{node.data}', end='')
            node = node.next
        print('\n')