#define min(a,b) (a<b?a:b)
#define and &&

int prefixCount(char ** words, int wordsSize, char * pref){
    int res=0,prelen=strlen(pref);
    for(int i=0;i<wordsSize;++i){
        int ok=1,j,wlen=strlen(words[i]);
        for(j=0;j<min(wlen,prelen);++j){
            if(words[i][j]!=pref[j]){
                ok=0;
                break;
            }
        }
        if(ok and j==prelen){
            ++res;
        }
    }
    return res;
}