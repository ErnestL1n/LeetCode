class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=2,res=0;
        while(i<s.size()){
            if(s[i]!=s[i-1] and s[i]!=s[i-2] and s[i-1]!=s[i-2])
                ++res;
            ++i;
        }
        return res;
    }
};