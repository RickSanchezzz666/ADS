import AVLTree

tree = AVLTree.AVLTree(6)
root = tree.root

root = tree.insert_node(root, 2)
root = tree.insert_node(root, 12)
root = tree.insert_node(root, 45)
root = tree.insert_node(root, 3)
root = tree.insert_node(root, 15)
root = tree.insert_node(root, 18)
root = tree.insert_node(root, 16)

tree.traversal_in_order(root)

print('\nAfter deleting: ')

root = tree.delete_node(root, 15)

tree.traversal_in_order(root)