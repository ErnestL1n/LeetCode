


typedef struct {
    int* table
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* obj=(MyHashMap*)malloc(sizeof(MyHashMap));
    obj->table=(int*)malloc(sizeof(int)*1000001);
    for(int i=0;i<1000001;++i){
        obj->table[i]=-1;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->table[key]=value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->table[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->table[key]=-1;
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