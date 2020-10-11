class MyHashMap {
    private static class ListNode{
        int key,val;
        ListNode next;
        public ListNode(int key,int val){
            this.key=key;
            this.val=val;
        }    
    }
    
    //The number of operations will be in the range of [1, 10000]
    ListNode[] buckets=new ListNode[10000];
    /** Initialize your data structure here. */
    
    public MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int index=getIndex(key);
        ListNode prev=findElement(key,index);
        if(prev.next==null)
            prev.next=new ListNode(key,value);
        else
            prev.next.val=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int index=getIndex(key);
        ListNode prev=findElement(key,index);
        return prev.next==null?-1:prev.next.val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int index=getIndex(key);
        ListNode prev=findElement(key,index);
        if(prev.next!=null)
            prev.next=prev.next.next;
    }
    public int getIndex(int key){
        //The number of operations will be in the range of [1, 10000]
        //return 1~9999~0
        //thus we need prev
        return Integer.hashCode(key)%buckets.length;
    }
    public ListNode findElement(int key,int index){
        if(buckets[index]==null)
            return buckets[index]=new ListNode(-1,-1);
        ListNode prev=buckets[index];
        while(prev.next!=null&&prev.next.key!=key)
            prev=prev.next;
        return prev;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
 
 
 
 
 
 
 
 
 //simple solution
 //size>10000
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