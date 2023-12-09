class HashTable:
    def __check_prime(self, n):
        if n <= 1: return False
        for i in range(2, int(n / 2)):
            if n % i == 0:
                return False
        return True
    
    def __get_prime(self, n):
        while self.__check_prime(n) is not True:
            n += 1
        return n

    def __hash_function(self, key):
        return (key % self.__capacity)

    def __init__(self, size):
        self.__capacity = self.__get_prime(size)
        self.__table = [[] for _ in range(self.__capacity)]

    def insert_into_table(self, key, data):
        index = self.__hash_function(key)
        if self.__table[index] == []:
            self.__table[index] = [key, data]
            return
        else:
            self.insert_into_table(key + 1, data)

    def delete_from_table(self, key_to_del):
        index = self.__hash_function(key_to_del)
        if self.__table[index][0] == key_to_del:
            self.__table[index] = []
        else:    
            print("This Key is not found!\n")


    def search_key(self, key_to_find):
        index = self.__hash_function(key_to_find)
        if self.__table[index][0] == key_to_find:
            return self.__table[index][1]
        else:
            print("This Key is not found!")

    def display_table(self):
        print("This is your Hash Table: \n", end="")
        for elem in self.__table:
            if elem == []:
                print("NIL\n", end="")
            else:
                print(f"{elem[1]}\n", end="")
        print("\n")