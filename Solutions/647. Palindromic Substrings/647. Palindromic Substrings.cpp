class Solution {
public:
    int res=0;
    int countSubstrings(string s) {
        for(int i=0;i<s.size();++i){
            extendPal(s,i,i);
            extendPal(s,i,i+1);
        }
        return res;
    }
    void extendPal(string& s,int i,int j){
        while(i>=0 and j<s.size() and s[i]==s[j]){
            ++res,--i,++j;
        }
    }
};