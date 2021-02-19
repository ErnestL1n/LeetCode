//simple solution ,c base ,so in c++ it is faster
#define SIZE 10000
class MyHashMap {
public:
    int hash(int x){
        return x%SIZE;
    }
    int* table;
    MyHashMap* obj;
    /** Initialize your data structure here. */
    MyHashMap() {
        obj=(MyHashMap*)malloc(sizeof(MyHashMap)*SIZE);
        obj->table=(int*)malloc(sizeof(int)*SIZE);
        for(int i=0;i<SIZE;++i)
            obj->table[i]=-1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        obj->table[hash(key)]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return obj->table[key%SIZE];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        obj->table[key%SIZE]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 