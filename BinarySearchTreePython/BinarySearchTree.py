class BinarySearchTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self, data):
        self.root = self.Node(data)

    def __min_value_node(self, node: Node):
        current = node
        while current != None and current.left != None:
            current = current.left
        return current

    def traversal_in_order(self, root:Node):
        if root:
            self.traversal_in_order(root.left)
            print(f'{root.data}->', end='')
            self.traversal_in_order(root.right)

    def insert_into_tree(self, root: Node, data):
        if root == None: return self.Node(data)
        if data < root.data: root.left = self.insert_into_tree(root.left, data)
        else: root.right = self.insert_into_tree(root.right, data)
        return root

    def delete_from_tree(self, root: Node, data):
        if root == None: return root
        if data < root.data: root.left = self.delete_from_tree(root.left, data)
        elif data > root.data: root.right = self.delete_from_tree(root.right, data)
        else:
            if root.left == None:
                temp = root.right
                del root
                return temp
            elif root.right == None:
                temp = root.left
                del root
                return temp
            
            temp = self.__min_value_node(root.right)
            root.data = temp.data
            root.right = self.delete_from_tree(root.right, temp.data)
        return root

