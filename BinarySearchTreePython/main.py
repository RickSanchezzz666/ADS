import BinarySearchTree

tree = BinarySearchTree.BinarySearchTree(5)

root = tree.root

root = tree.insert_into_tree(root, 2)
root = tree.insert_into_tree(root, 6)
root = tree.insert_into_tree(root, 3)
root = tree.insert_into_tree(root, 9)
root = tree.insert_into_tree(root, 12)
root = tree.insert_into_tree(root, 11)
root = tree.insert_into_tree(root, 7)

root = tree.delete_from_tree(root, 9)
root = tree.delete_from_tree(root, 2)

print('Tree Traversal In Order: ', end='')
tree.traversal_in_order(root)
print()