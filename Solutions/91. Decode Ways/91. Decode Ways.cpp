// Top down DP + memo
class Solution {
public:
    int memo[100]={};
    int numDecodings(string s) {
        return dp(s,0);
    }
    int dp(string& s,int i){
        if(i==s.size())
            return 1;
        if(memo[i]!=0)
            return memo[i];
        int res=0;
        if(s[i]!='0')
            res+=dp(s,i+1);
        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<='6')))
            res+=dp(s,i+2);
        return memo[i]=res;
    }
};