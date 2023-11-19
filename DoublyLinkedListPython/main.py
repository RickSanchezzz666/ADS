class DoublyLinkedList:
    class Node:
        def __init__(self, data = None):
            self.data = data
            self.next = None
            self.prev = None

    def __init__(self, size):
        self.__count = -1
        self.__size = size
        self.__head = self.Node()

    def __is_list_empty(self):
        return self.__count <= -1
    
    def __is_list_full(self):
        return self.__count >= self.__size - 1
    
    def insert_at_the_beginning(self, new_data):
        if self.__is_list_full(): 
            print('The list is Full!\n')
            return
        new_node = self.Node(new_data)
        new_node.next = self.__head

        if(self.__head is not None):
            self.__head.prev = new_node

        self.__head = new_node

        self.__count += 1

    def instert_in_between_nodes(self, prev_node_val, new_data):
        if self.__is_list_full(): 
            print('The list is Full!\n')
            return
        node = self.__head
        while node.next:
            if(node.data == prev_node_val): break
            node = node.next
        
        if(node.data != prev_node_val):
            print('Wrong Previous Value!')
            return

        new_node = self.Node(new_data)

        if(node.next != None):
            next = node.next
            next.prev = new_node
            node.next = new_node
            new_node.prev = node
            new_node.next = next
        else: 
            node.next = new_node
            new_node.prev = node

        self.__count += 1

    def insert_at_the_end(self, new_data):
        if self.__is_list_full(): 
            print('The list is Full!\n')
            return
        
        node = self.__head
        if(node is None or node.data is None):
            self.insert_at_the_beginning(new_data)
            return

        for _ in range(self.__count):
            node = node.next

        new_node = self.Node(new_data)
        node.next = new_node
        new_node.prev = node

        self.__count += 1

    def display_list(self):
        if self.__is_list_empty(): 
            print('The list is Empty!\n')
            return
        
        node = self.__head
        print(f'Your list is: {node.data}', end='')
        node = node.next
        for _ in range(self.__count):
            print(f'->{node.data}', end='')
            node = node.next
        print('\n')

list = DoublyLinkedList(5)

list.insert_at_the_beginning(13)

list.instert_in_between_nodes(13, 26)

list.insert_at_the_beginning(15)

list.instert_in_between_nodes(15, 74)

list.insert_at_the_end(66)


list.display_list()