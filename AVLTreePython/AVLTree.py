class AVLTree:
    class Node:
        def __init__(self, key):
            self.key = key
            self.left = None
            self.right = None
            self.height = 1

    def __init__(self, key):
        self.root = self.Node(key)

    def __get_max(self, x, y):
        return (x if x > y else y)

    def __get_height(self, node: Node):
        if (node != None): return node.height
        return 0

    def __get_balance_factor(self, node: Node):
        if (node != None): return (self.__get_height(node.left) - self.__get_height(node.right))
        return 0

    def __get_min_val_node(self, node: Node):
        current = node
        while(current.left != None):
            current = current.left
        return current

    def __update_height(self, node: Node):
        node.height = self.__get_max(self.__get_height(node.left), self.__get_height(node.right)) + 1

    def left_rotate(self, x: Node):
        y = x.right
        temp = y.left
        y.left = y
        x.right = temp


    def right_rotate(self, y: Node):
        pass

    def update_balance_factor(self, node: Node, key):
        self.__update_height(node)
        balance_factor = self.__get_balance_factor(node)
        if balance_factor > 1:
            if key < node.left.key: return self.right_rotate(node)
            elif key > node.left.key: 
                node.left = self.left_rotate(node.left)
                return self.right_rotate(node)
        elif balance_factor < -1:
            if key > node.right.key: return self.left_rotate(node)
            elif key < node.right.key: 
                node.right = self.right_rotate(node.right)
                return self.left_rotate(node)
        return node

    def insert_node(self, node: Node, key):
        if not node: return self.Node(key)
        elif key < node.key: node.left = self.insert_node(node.left, key)
        elif key > node.key: node.right = self.insert_node(node.right, key)
        else: return node

        self.update_balance_factor(node, key)

    def delete_node(self):
        pass

    def traversal_in_order(self, node: Node):
        if (node):
            self.traversal_in_order(node.left)
            print(f'{"root:" if node.key == self.root.key else ""}{node.key}->')
            self.traversal_in_order(node.right)