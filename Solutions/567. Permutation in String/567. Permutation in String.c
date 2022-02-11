bool allzero(int* cnt){
    for(int i=0;i<26;++i){
        if(cnt[i]!=0){
            return false;
        }
    }
    return true;
}

bool checkInclusion(char * s1, char * s2){
    int m=strlen(s1),n=strlen(s2);
    if(m>n){
        return false;
    }
    int *cnt=(int*)calloc(26,sizeof(int));
    for(int i=0;i<m;++i){
        ++cnt[s1[i]-'a'];
        --cnt[s2[i]-'a'];
    }
    if(allzero(cnt)){
        return true;
    }
    for(int i=m;i<n;++i){
        --cnt[s2[i]-'a'];
        ++cnt[s2[i-m]-'a'];
        if(allzero(cnt)){
            return true;
        }
    }
    return false;
}