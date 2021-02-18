


typedef struct {
    uint8_t h[1000001];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    return (MyHashSet*)calloc(1,sizeof(MyHashSet));
}

void myHashSetAdd(MyHashSet* obj, int key) {
  obj->h[key]=1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
  obj->h[key]=0;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
  return obj->h[key]==1;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/