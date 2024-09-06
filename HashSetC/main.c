#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>



typedef struct {
    int size;
    int *table;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* hashSet = (MyHashSet *)malloc(sizeof(MyHashSet));

    hashSet->size = 1000001;
    hashSet->table = (int *)malloc(sizeof(int) * hashSet->size);

    for (size_t i = 0; i < hashSet->size; ++i) {
        hashSet->table[i] = INT_MAX;
    }

    return hashSet;
}

int hashFunction(MyHashSet* obj, int key) {
    return (key % obj->size);
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = hashFunction(obj, key);
    if (obj->table[index] == INT_MAX)
        obj->table[index] = key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = hashFunction(obj, key);
    if (obj->table[index] != INT_MAX)
        obj->table[index] = INT_MAX;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = hashFunction(obj, key);
    return (obj->table[index] != INT_MAX);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->table);
    free(obj);
}