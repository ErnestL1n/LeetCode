class Solution {
public:
    string replaceDigits(string s) {
        for(int i=0,j=1;j<s.size();i+=2,j+=2)
            s[j]=s[i]+(s[j]-'0');
        return s;
    }
};