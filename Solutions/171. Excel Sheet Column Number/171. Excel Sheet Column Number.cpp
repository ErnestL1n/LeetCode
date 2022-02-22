class Solution {
public:
    int titleToNumber(string s) {
        int res=0,n=s.size();
        for(int i=0;i<n;++i){
            res=res*26+(s[i]-'A'+1);
        }
        return res;
    }
};