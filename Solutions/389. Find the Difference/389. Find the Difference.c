//xor
char findTheDifference(char * s, char * t){
    int n=strlen(t);
    char c=t[n-1];
    for(int i=0;i<n-1;++i){
        c^=s[i];
        c^=t[i];
    }
    return c;
}

//count
char findTheDifference(char * s, char * t){
    int *cnt1=(int*)calloc(26,sizeof(int));
    int *cnt2=(int*)calloc(26,sizeof(int));
    int ssz=strlen(s),tsz=strlen(t);
    for(int i=0;i<tsz;++i){
        if(i!=ssz){
            ++cnt1[s[i]-'a'];
        }
        ++cnt2[t[i]-'a'];
    }
    int res;
    for(res=0;res<26;++res){
        if(cnt2[res]-cnt1[res]==1){
            break;
        }
    }
    return res+'a';
}