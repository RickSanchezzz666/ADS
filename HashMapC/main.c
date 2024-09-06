typedef struct {
    int size;
    int *map;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* hashMap = (MyHashMap* )malloc(sizeof(MyHashMap));

    hashMap->size = 1e6 + 1;
    hashMap->map = (int* )malloc(sizeof(int) * hashMap->size);

    for(size_t i = 0; i < hashMap->size; ++i) {
        hashMap->map[i] = -1;
    }

    return hashMap;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->map[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->map[key];    
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->map[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->map);
    free(obj);
}
