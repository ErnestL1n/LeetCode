#define and &&

bool checkString(char * s){
    char a=false,b=false;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='a'){
            a=true;
            if(a and b){
                return false;
            }
        }else{
            b=true;
        }
    }
    return true;
}