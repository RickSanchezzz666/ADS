import CircularLinkedList as CircularListModule

list = CircularListModule.CircularLinkedList(5)

list.insertion_at_the_end(12)
list.insertion_at_the_beginning(1)
list.insertion_at_the_end(31)
list.insertion_after_node(52, 2)
list.insertion_at_the_end(26)

list.delete_at_the_beginning()
list.delete_at_the_end()

list.delete_node(1)

list.display_list()

node_search = list.search_node(31)

print(f'Found node 31: {node_search}')