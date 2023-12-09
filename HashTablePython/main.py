import HashTable

keys = [123, 132, 443, 54, 52, 93, 10]
data = [21, 32, 93, -2, 34, 66, 0]

table = HashTable.HashTable(len(keys))

for i in range(len(keys)):
    table.insert_into_table(keys[i], data[i])

table.delete_from_table(123)

table.display_table()

elem = table.search_key(132)

print(elem)