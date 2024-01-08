import BinaryTree

tree = BinaryTree.BinaryTree(1)

tree.root.left = tree.new_node(4)
tree.root.right = tree.new_node(6)
tree.root.left.left = tree.new_node(9)
tree.root.left.right = tree.new_node(3)

print('In Order Traversal: ', end='')
tree.traversal_in_order(tree.root)
print()

print('Pre Order Traversal: ', end='')
tree.traversal_pre_order(tree.root)
print()

print('Post Order Traversal: ', end='')
tree.traversal_post_order(tree.root)
