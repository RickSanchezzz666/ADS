class Node:
    def __init__(self, leaf=False):
        self.leaf = leaf

        self.keys = []
        self.children = []

class BTree(Node):
    def __init__(self, degree: int):
        self.root = Node(True)
        self.tree_degree = degree

    def __insert_in_not_full(self, node: Node, value: int):
        i = len(node.keys) - 1
        if node.leaf:
            node.keys.append((None, None))
            while i >= 0 and value[0] < node.keys[i][0]:
                node.keys[i + 1] = node.keys[i]
                i -= 1
            node.keys[i + 1] = value
        else:
            while i >= 0 and value[0] < node.keys[i][0]:
                i -= 1
            i += 1
            if i < len(node.children) and len(node.children[i].keys) == (2 * self.tree_degree) - 1:
                self.__split_child(node, i)
                if value[0] > node.keys[i][0]:
                    i += 1
            self.__insert_in_not_full(node.children[i], value)



    def __split_child(self, node: Node, i: int): 
        degree = self.tree_degree
        child = node.children[i]
        temp = Node(child.leaf)
        child.children.insert(i + 1, temp)
        node.keys.insert(i, child.keys[degree - 1])
        temp.keys = child.keys[degree: (2 * degree) - 1]
        child.keys = child.keys[0: degree - 1]
        if not child.leaf:
            temp.children = child.children[degree: 2 * degree]
            child.children = child.children[0: degree - 1]


    def delete_key(self, node: Node, value):
        t = self.tree_degree
        i = 0
        while i < len(node.keys) and value[0] > node.keys[i][0]:
            i += 1
        if node.leaf:
            if i < len(node.keys) and node.keys[i][0] == value[0]:
                node.keys.pop(i)
                return
            return

        if i < len(node.keys) and node.keys[i][0] == value[0]:
            return self.__delete_internal_node(node, value, i)
        elif len(node.child[i].keys) >= t:
            self.delete(node.child[i], value)
        else:
            if i != 0 and i + 2 < len(node.child):
                if len(node.child[i - 1].keys) >= t:
                    self.__delete_sibling(node, i, i - 1)
                elif len(node.child[i + 1].keys) >= t:
                    self.__delete_sibling(node, i, i + 1)
                else:
                    self.__delete_merge(node, i, i + 1)
            elif i == 0:
                if len(node.child[i + 1].keys) >= t:
                    self.__delete_sibling(node, i, i + 1)
                else:
                    self.__delete_merge(node, i, i + 1)
            elif i + 1 == len(node.child):
                if len(node.child[i - 1].keys) >= t:
                    self.__delete_sibling(node, i, i - 1)
                else:
                    self.__delete_merge(node, i, i - 1)
            self.delete(node.child[i], value)

    def __delete_internal_node(self, node: Node, value, i):
        t = self.tree_degree
        if node.leaf:
            if node.valueeys[i][0] == value[0]:
                node.keys.pop(i)
                return
            return

        if len(node.child[i].keys) >= t:
            node.keys[i] = self.__delete_predecessor(node.child[i])
            return
        elif len(node.child[i + 1].keys) >= t:
            node.keys[i] = self.__delete_successor(node.child[i + 1])
            return
        else:
            self.__delete_merge(node, i, i + 1)
            self.__delete_internal_node(node.child[i], value, self.tree_degree - 1)

    def __delete_predecessor(self, node: Node):
        if node.leaf:
            return node.keys.pop()
        n = len(node.keys) - 1
        if len(node.children[n].keys) >= self.tree_degree:
            self.__delete_sibling(node, n + 1, n)
        else:
            self.__delete_merge(node, n, n + 1)
        return self.____delete_predecessor(node.children[n])

    def __delete_successor(self, node: Node):
        if node.leaf:
            return node.keys.pop(0) if node.keys else None
        if len(node.children[1].keys) >= self.tree_degree:
            self.__delete_sibling(node, 0, 1)
        else:
            self.__delete_merge(node, 0, 1)
        return self.__delete_successor(node.children[0])


    def __delete_merge(self, node: Node, i, j):
        cnode = node.child[i]

        if j > i:
            rsnode = node.child[j]
            cnode.keys.append(node.keys[i])
            for k in range(len(rsnode.keys)):
                cnode.keys.append(rsnode.keys[k])
                if len(rsnode.child) > 0:
                    cnode.child.append(rsnode.child[k])
            if len(rsnode.child) > 0:
                cnode.child.append(rsnode.child.pop())
            new = cnode
            node.keys.pop(i)
            node.child.pop(j)
        else:
            lsnode = node.child[j]
            lsnode.keys.append(node.keys[j])
            for i in range(len(cnode.keys)):
                lsnode.keys.append(cnode.keys[i])
                if len(lsnode.child) > 0:
                    lsnode.child.append(cnode.child[i])
            if len(lsnode.child) > 0:
                lsnode.child.append(cnode.child.pop())
            new = lsnode
            node.keys.pop(j)
            node.child.pop(i)

        if node == self.root and len(node.keys) == 0:
            self.root = new

    def __delete_sibling(self, node: Node, i, j):
        cnode = node.child[i]
        if i < j:
            rsnode = node.child[j]
            cnode.keys.append(node.keys[i])
            node.keys[i] = rsnode.keys[0]
            if len(rsnode.child) > 0:
                cnode.child.append(rsnode.child[0])
                rsnode.child.pop(0)
            rsnode.keys.pop(0)
        else:
            lsnode = node.child[j]
            cnode.keys.insert(0, node.keys[i - 1])
            node.keys[i - 1] = lsnode.keys.pop()
            if len(lsnode.child) > 0:
                cnode.child.insert(0, lsnode.child.pop())
    
    def display_tree(self, node: Node, level = 0): 
        print(f"Level {level}: {len(node.keys)} keys: ", end='')
        for key in node.keys:
            print(key, end='')
        print()
        level += 1
        if len(node.children) > 0:
            for child in node.children:
                self.display_tree(child, level)

    def insert_in_tree(self, value):
        root = self.root
        if len(root.keys) == (2 * self.tree_degree) - 1:
            temp = Node()
            self.root = temp
            temp.children.insert(0, root)
            self.__split_child(temp, 0)
            self.__insert_in_not_full(temp, value)
        else: self.__insert_in_not_full(root, value)