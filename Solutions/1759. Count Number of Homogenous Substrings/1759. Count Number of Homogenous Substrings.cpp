class Solution {
public:
    int countHomogenous(string s) {
        long cnt=0,res=0;
        long mod=1e9+7;
        for(int i=0;i<s.size();++i){
            if(i>0&&s[i-1]==s[i])
                ++cnt;
            else
                cnt=1;
            res+=cnt;
        }
        return res%mod;
    }
};