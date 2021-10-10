struct trie{
    bool isword;
    trie* ch[26]={};
};
class Trie {
public:
    struct trie root;
    Trie() {
        
    }
    // marking end isword=true
    void insert(string word) {
        auto p=&root;
        for(const auto& c:word){
            if(p->ch[c-'a']==nullptr)
                p->ch[c-'a']=new trie();
            p=p->ch[c-'a'];
        }
        p->isword=true;
    }
    
    // checking end if isword
    bool search(string word) {
        auto p=&root;
        for(const auto& c:word){
            if(!p)
                return false;
            p=p->ch[c-'a'];
        }
        return p and p->isword;
    }
    
    // checking trie exists or not
    bool startsWith(string prefix) {
        auto p=&root;
        for(const auto& c:prefix){
            if(!p)
                break;
            p=p->ch[c-'a'];
        }
        return p!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */