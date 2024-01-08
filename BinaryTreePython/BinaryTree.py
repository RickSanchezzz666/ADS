class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self, data):
        self.root = self.Node(data)
    
    def new_node(self, data):
        new_node = self.Node(data)
        return new_node
    
    def traversal_in_order(self, node: Node):
        if node != None:
            self.traversal_in_order(node.left)
            print(f'{node.data}->', end='')
            self.traversal_in_order(node.right)

    def traversal_pre_order(self, node: Node):
        if node != None:
            print(f'{node.data}->', end='')
            self.traversal_in_order(node.left)
            self.traversal_in_order(node.right)

    def traversal_post_order(self, node: Node):
        if node != None:
            self.traversal_in_order(node.left)
            self.traversal_in_order(node.right)
            print(f'{node.data}->', end='')

    def is_tree_full(self, root: Node):
        if root == None: return True
        if root.left == None and root.right == None: return True
        if root.left and root.right: return (self.is_tree_full(root.left) and self.is_tree_full(root.right))
        return False
    