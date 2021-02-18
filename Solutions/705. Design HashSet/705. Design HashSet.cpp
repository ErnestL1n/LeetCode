class MyHashSet {
public:
    uint8_t h[1000001];
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        h[key]=1;
    }
    
    void remove(int key) {
        h[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return h[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */