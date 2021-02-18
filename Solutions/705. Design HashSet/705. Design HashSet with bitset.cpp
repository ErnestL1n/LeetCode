class MyHashSet {
public:
    bitset<1000001> bs;
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        bs.set(key);
    }
    
    void remove(int key) {
        bs.reset(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bs.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */