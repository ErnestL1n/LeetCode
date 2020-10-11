//simple solution ,c base ,so in c++ it is faster
#define SIZE 100000
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
 
 
 
 
 
 //vector solution
 class MyHashMap {
private:
    vector<int> vec; 
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vec=vector<int>(1000000,-1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vec[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return vec[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vec[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
 
 
 
 
 
 //buckets version
 class MyHashMap {
public:
    class ListNode{
    public:
        int val,key;
        ListNode* next;
        ListNode(int key,int val){
            this->key=key;
            this->val=val;
            //important to avoid member access within misaligned address
            this->next=nullptr;
        }
    };
    vector<ListNode*> buckets;
    /** Initialize your data structure here. */
    MyHashMap() {
        this->buckets=vector<ListNode*>(10000,new ListNode(-1,-1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index=getIndex(key);
        ListNode* prev=findElement(key,index);
        if(prev->next!=nullptr)
            prev->next->val=value;
        else
            prev->next=new ListNode(key,value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index=getIndex(key);
        ListNode* prev=findElement(key,index);
        return prev->next==nullptr?-1:prev->next->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index=getIndex(key);
        ListNode* prev=findElement(key,index);
        if(prev->next!=nullptr)
            prev->next=prev->next->next;
    }
    
    int getIndex(int key){
        return key%buckets.size();
    }
    
    ListNode* findElement(int key,int index){
        ListNode* prev=buckets[index];
        while(prev->next!=nullptr&&prev->next->key!=key)
            prev=prev->next;
        return prev;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 