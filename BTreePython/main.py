import BTree

tree = BTree.BTree(3)

tree.insert_in_tree((6,))
tree.insert_in_tree((2,))
tree.insert_in_tree((7,))
tree.insert_in_tree((12,))
tree.insert_in_tree((13,))    

tree.display_tree(tree.root)

tree.delete_key(tree.root, (7,))
tree.display_tree(tree.root)
