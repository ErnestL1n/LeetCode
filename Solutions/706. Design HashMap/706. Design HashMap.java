class MyHashMap {
    public int hash(int x){
        return x%100000;
    }
    private int[] table;
    /** Initialize your data structure here. */
    public MyHashMap() {
        table=new int[100000];
        for(int i=0;i<100000;++i)
            table[i]=-1;
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        table[hash(key)]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return table[key%100000];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        table[key%100000]=-1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */