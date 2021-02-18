class MyHashSet {
    int[] h=new int[1000001];
    /** Initialize your data structure here. */
    public MyHashSet() {

    }
    
    public void add(int key) {
        h[key]=1;
    }
    
    public void remove(int key) {
        h[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return h[key]==1;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */