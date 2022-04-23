class MyHashMap {
    int[] table;
    public MyHashMap() {
        table=new int[1000001];
        Arrays.fill(table,-1);
    }
    
    public void put(int key, int value) {
        table[key]=value;
    }
    
    public int get(int key) {
        return table[key];   
    }
    
    public void remove(int key) {
        table[key]=-1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */