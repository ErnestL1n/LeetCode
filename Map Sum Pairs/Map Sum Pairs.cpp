class MapSum {
public:
    struct trie{
        trie* ch[26]={};
        int sum=0;
    }root;
    unordered_map<string,int>pairs;
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto p=&root;
        for(auto i=0;i<key.size();p->sum+=val-pairs[key],++i)
            p=p->ch[key[i]-'a']=p->ch[key[i]-'a']==nullptr?new trie():p->ch[key[i]-'a'];
        pairs[key]=val;
    }
    
    int sum(string prefix) {
        auto p=&root;
        for(auto i=0;i<prefix.size()&&p!=nullptr;p = p->ch[prefix[i] - 'a'], ++i);
        return p==nullptr?0:p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */