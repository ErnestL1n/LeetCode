class Solution {
public:
    int myAtoi(string s) {
        int sign=1,base=0,i=0;
        while(s[i]==' '){
            ++i;
        }
        if(s[i]=='-' or s[i]=='+'){
            sign=1-2*(s[i++]=='-'); 
        }
        while(s[i]>='0' and s[i]<='9') {
            if (base>INT_MAX/10 or (base==INT_MAX/10 and s[i]-'0'>7)){
                if(sign==1) {
                    return INT_MAX;
                }else{
                  return INT_MIN;  
                } 
            }
            base=10*base+(s[i++]-'0');
        }
        return base*sign;
    }
};