import BinaryTree

def check_tree_type(*args):
    print(f'Is This Tree is {args[0]}: ', end='')
    result = args[1](args[2])
    print('True' if result else 'False', end='\n')

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
print()

#Binary Tree Types

#Full
check_tree_type('Full', tree.is_tree_full, tree.root)

#Perfect
tree.root.right.left = tree.new_node(29)
tree.root.right.right = tree.new_node(12)

check_tree_type('Perfect', tree.is_tree_perfect, tree.root)
