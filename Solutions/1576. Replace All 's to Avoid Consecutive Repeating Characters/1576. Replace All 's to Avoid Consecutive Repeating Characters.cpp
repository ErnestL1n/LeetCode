class Solution {
public:
    string modifyString(string s) {
        for(int i=0;i<s.size();++i){
            if(s[i]=='?')
                for(s[i]='a';s[i]<='c';++s[i])
                    if((i==0 or s[i-1]!=s[i]) and (i==s.size()-1 or s[i]!=s[i+1]))
                        break;
        }
        return s;
    }
};