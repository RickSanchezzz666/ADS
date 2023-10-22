class Stack:
    __stack = []
    __top = -1

    def is_stack_empty(self):
        if self.__top == -1 and len(self.__stack) == 0: 
            print('\nThe Stack is Empty!\n')
            return True
        else: return False

    def get_peek_elem(self):
        if(self.is_stack_empty()): return
        peek_elem = self.__stack[self.__top]
        print(f'Your peek element is {peek_elem}!')
        return peek_elem
    
    def push_in_stack(self, value):
        self.__stack.append(value)
        self.__top += 1

    def pop_from_stack(self):
        if(self.is_stack_empty()): return
        self.__stack.pop()
        self.__top -= 1

    def print_stack(self):
        if(self.is_stack_empty()): return
        for i in self.__stack:
            print(f'[{i}]')

    def __init__(self, stack = [], top = -1):
        self.__stack = stack
        self.__top = top

stack = Stack()

stack.push_in_stack(6)
stack.push_in_stack(14)
stack.push_in_stack(16)

stack.get_peek_elem()

stack.pop_from_stack()

stack.push_in_stack(124)

stack.print_stack()



