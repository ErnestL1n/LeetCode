struct trie{
    string item="";
    trie* ch[26]={};
};

class WordDictionary{
public:
    struct trie root;
    WordDictionary(){
        
    }
    
    void addWord(string word){
        auto p=&root;
        for(const auto& c:word){
            if(!p->ch[c-'a']){
                p->ch[c-'a']=new trie();
            }
            p=p->ch[c-'a'];
        }
        p->item=word;
    }
    
    bool search(string word){
        return match(word,0,&root);
    }
    
    bool match(string& s,int k,trie* node) {
        if(k==s.size()){
            return node->item!="";
        }
        if(s[k]!='.') {
            return node->ch[s[k]-'a'] and match(s,k+1,node->ch[s[k]-'a']);
        }else{
            for(int i=0;i<26;++i){
                if(node->ch[i]){
                    if(match(s,k+1,node->ch[i])){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */