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
    
    void insert(string key,int val) {
        trie* p=&root;
        for(int i=0;i<key.size();++i){
            if(p->ch[key[i]-'a']!=nullptr){
                p->ch[key[i]-'a']=p->ch[key[i]-'a'];
                p=p->ch[key[i]-'a'];
            }else{
                p->ch[key[i]-'a']=new trie();
                p=p->ch[key[i]-'a'];
            }
            p->sum+=val-m[key];
        }
        m[key]=val;
    }
    
    int sum(string prefix) {
        trie* p=&root;
        for(int i=0;i<prefix.size() and p!=nullptr;++i)
            p=p->ch[prefix[i]-'a'];
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