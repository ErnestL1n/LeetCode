

bool isSubsequence(char * s, char * t){
    int i,j;
    int slen=strlen(s),tlen=strlen(t);
    for(i=0,j=0;j<tlen;){
        if(s[i]==t[j]){
            ++i;
            ++j;
        }else{
            ++j;
        }
    }
    return i==slen;
}