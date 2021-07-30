class MapSum {
public:
    /** Initialize your data structure here. */
    struct trie{
            trie* ch[26]={};
            int sum=0;
        }root;
    unordered_map<string,int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto p=&root;
        for(int i=0;i<key.size();p->sum+=val-m[key],++i)
            p=p->ch[key[i]-'a']=p->ch[key[i]-'a']?p->ch[key[i]-'a']:new trie();
        m[key]=val;
    }
    
    int sum(string prefix) {
        auto p=&root;
        for (int i=0; i<prefix.size() and p;p=p->ch[prefix[i]-'a'],++i) ;
        return p?p->sum:0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */