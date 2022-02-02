

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int* res=NULL;
    *returnSize=0;
    int slen=strlen(s),plen=strlen(p);
    if(slen<plen){
        return res;
    }
    int *cnt=(int*)calloc(26,sizeof(int));
    for(int i=0;i<plen;++i){
        ++cnt[p[i]-'a'];
    }
    int i=0,j=0;
    while(j<slen){
        if(cnt[s[j]-'a']>0){
            --plen;
        }
        --cnt[s[j]-'a'];
        ++j;
        if(plen==0){
            ++(*returnSize);
            res=(int*)realloc(res,(*returnSize)*sizeof(int));
            res[(*returnSize)-1]=i;
        }
        if(j-i==strlen(p)){
            if(cnt[s[i]-'a']>=0){
                ++plen;
            }
            ++cnt[s[i]-'a'];
            ++i;
        }
    }
    return res;
}