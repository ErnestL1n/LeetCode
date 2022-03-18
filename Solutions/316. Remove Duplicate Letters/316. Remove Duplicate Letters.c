

char * removeDuplicateLetters(char * s){
    int *cnt=calloc(26,sizeof(int));
    bool *visited=calloc(26,sizeof(bool));
    for(int i=0;i<strlen(s);++i){
        ++cnt[s[i]-'a'];
    }
    char *res=calloc(0,sizeof(char));
    int sz=0;
    for(int i=0;i<strlen(s);++i){
        int idx=s[i]-'a';
        --cnt[idx];
        if(visited[idx]){
            continue;
        }
        while(sz>0 && s[i]<res[sz-1] && cnt[res[sz-1]-'a']!=0){
            visited[res[sz-1]-'a']=false;
            res=realloc(res,--sz);
        }
        res=realloc(res,++sz);
        res[sz-1]=s[i];
        visited[idx]=true;
    }
    res=realloc(res,++sz);
    res[sz-1]='\0';
    return res;
}