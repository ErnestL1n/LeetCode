#define and &&

bool detectCapitalUse(char * word){
    int n=strlen(word);
    if(n==1){
            return true;
        }
    if(isupper(word[0]) and isupper(word[1])){
        for(int i=2;i<n;++i){
            if(islower(word[i])){
                return false;
            }
        }
    }else{
        for(int i=2;i<n;++i){
            if(isupper(word[i])){
                return false;
            }
        }
    }
    return islower(word[0]) and isupper(word[1])?false:true;
}