class MyHashMap {
public:
    int SIZE=1000001;
    int* table;
    MyHashMap *hashmap;
    MyHashMap() {
        hashmap=(MyHashMap*)malloc(sizeof(MyHashMap));
        hashmap->table=(int*)malloc(sizeof(int)*SIZE);
        for(int i=0;i<SIZE;++i){
            hashmap->table[i]=-1;
        }
    }
    
    void put(int key, int value) {
        this->hashmap->table[key]=value;
    }
    
    int get(int key) {
        return this->hashmap->table[key];
    }
    
    void remove(int key) {
        this->hashmap->table[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */