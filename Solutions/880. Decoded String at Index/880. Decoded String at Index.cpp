class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long n=0,i;
        for(i=0;n<k;++i)
            n=isdigit(s[i])?n*(s[i]-'0'):n+1;
        while(i--){
            if(isdigit(s[i]))
                n/=s[i]-'0',k%=n;
            else if(k%n--==0)
                return string(1,s[i]);
        }
        return "";
    }
};