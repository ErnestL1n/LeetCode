#define SIZE 100000


typedef struct {
    int* table;
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* obj=(MyHashMap*)malloc(sizeof(MyHashMap));
    obj->table=(int*)malloc(sizeof(int)*SIZE);
    for(int i=0;i<SIZE;++i)
        obj->table[i]=-1;
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
  obj->table[key%SIZE]=value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
  return obj->table[key%SIZE];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
  obj->table[key%SIZE]=-1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/