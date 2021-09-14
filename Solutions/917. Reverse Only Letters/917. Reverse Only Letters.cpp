class Solution {
public:
    string reverseOnlyLetters(string s) {
        string tmp;
        for(int i=s.size()-1;i>=0;--i)
            if(isalpha(s[i]))
                tmp+=s[i];
        for(int i=0,j=0;i<s.size();++i)
            if(isalpha(s[i]))
                s[i]=tmp[j++];
        return s;
    }
};