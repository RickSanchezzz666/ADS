class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    class Height:
        def __init__(self):
            self.height = 0

    def __init__(self, data):
        self.root = self.Node(data)

    def __depth(self, node: Node):
        d = 0
        while(node != None):
            d += 1
            node = node.left
        return d
    
    def __is_tree_perfect_check(self, root: Node, d, level = 0):
        if root == None: return True
        if root.left == None and root.right == None: return (d == level + 1)
        if root.left == None or root.right == None: return False
        return self.__is_tree_perfect_check(root.left, d, level + 1) and self.__is_tree_perfect_check(root.right, d, level + 1)
    
    def __nodesCount(self, root: Node):
        if root == None: return 0
        return (1 + self.__nodesCount(root.left) + self.__nodesCount(root.right))
    
    def __is_tree_complete_check(self, root: Node, nodesNum, index = 0):
        if root == None: return True
        if index >= nodesNum: return False
        return self.__is_tree_complete_check(root.left, nodesNum, 2 * index + 1) and self.__is_tree_complete_check(root.right, nodesNum, 2 * index + 2)

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

    def is_tree_perfect(self, root: Node):
        d = self.__depth(root)
        return self.__is_tree_perfect_check(root, d)
    
    def is_tree_complete(self, root: Node):
        nodesNum = self.__nodesCount(root)
        return self.__is_tree_complete_check(root, nodesNum)

    def is_tree_balanced(self, root: Node, height: Height):
        left_height = self.Height()
        right_height = self.Height()

        if root == None:
            return True
        
        l = self.is_tree_balanced(root.left, left_height)
        r = self.is_tree_balanced(root.right, right_height)

        height.height = max(left_height.height, right_height.height) + 1

        if abs(left_height.height - right_height.height) >= 2: return False
        else: return l and r



    