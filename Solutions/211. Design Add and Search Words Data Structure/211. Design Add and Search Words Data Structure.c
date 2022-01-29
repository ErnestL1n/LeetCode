
#define and &&

typedef struct trie{
    struct trie* ch[26];
    bool isword;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary* obj=(WordDictionary*)calloc(1,sizeof(WordDictionary));
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    char* s=word;
    while(*s){
        if(!obj->ch[(*s)-'a']){
            obj->ch[(*s)-'a']=(WordDictionary*)calloc(1,sizeof(WordDictionary));
        }
        obj=obj->ch[(*s)-'a'];
        ++s;
    }
    obj->isword=true;
}

bool match(char* s,int k,WordDictionary* obj) {
    if(k==strlen(s)){
        return obj->isword;
    }
    if(s[k]!='.') {
        return obj->ch[s[k]-'a'] and match(s,k+1,obj->ch[s[k]-'a']);
    }else{
        for(int i=0;i<26;++i){
            if(obj->ch[i]){
                if(match(s,k+1,obj->ch[i])){
                    return true;
                }
            }
        }
    }
    return false;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
  return match(word,0,obj);
}

void wordDictionaryFree(WordDictionary* obj) {
    for(int i=0;i<26;++i) {
        if(!obj->ch[i]){
            continue;
        }
        wordDictionaryFree(obj->ch[i]);
    }
    free(obj);
}


/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/