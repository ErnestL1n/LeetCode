//trie struct solution
struct trie{
    int sum=0;
    trie *ch[26]={};
};
class MapSum {
public:
    struct trie root;
    unordered_map<string,int> m;
    
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto p=&root;
        for(const auto& c:key){
            if(p->ch[c-'a']!=nullptr){
                p->ch[c-'a']=p->ch[c-'a'];
                p=p->ch[c-'a'];
            }else{
                p->ch[c-'a']=new trie();
                p=p->ch[c-'a'];
            }
            p->sum+=val-m[key];
        }
        m[key]=val;
    }
    
    int sum(string prefix) {
        auto p=&root;
        for(const auto& c:prefix){
            if(!p)
                break;
            p=p->ch[c-'a'];
        }
        return p?p->sum:0;
    }
};


//map solution
class MapSum {
public:
    map<string,int> m;
    /** Initialize your data structure here. */    
    void insert(string key, int val) {
        m[key]=val;
    }

    int sum(string prefix) {
        int sum=0,n=prefix.size();
        // iterator first points to "ap" in map 
        // n=="ap".size()==2
        // "ap".substr(0,n)==prefix("ap")
        for(auto it=m.lower_bound(prefix);it!=m.end() and it->first.substr(0, n)==prefix;++it){
            cout <<it->first <<"\n";
            sum+=it->second;
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
