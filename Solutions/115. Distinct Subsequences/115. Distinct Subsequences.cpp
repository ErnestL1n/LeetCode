class Solution {
public:
    int numDistinct(string s, string t) {
        int m=t.size(),n=s.size();
        vector<vector<unsigned>> dp(m+1,vector<unsigned>(n+1)); 
        for(int j=0;j<=n;++j)
            dp[0][j]=1;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        return dp[m][n];
    }
};

//space opt
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=t.size(),n=s.size();
        vector<unsigned> dp(m+1);
        dp[0]=1;
        for(int j=1;j<=n;++j){
            unsigned prev=1;
            for(int i=1;i<=m;++i){
                unsigned tmp=dp[i];
                dp[i]=dp[i]+(s[j-1]==t[i-1]?prev:0);
                prev=tmp;
            }
        }
        return dp[m];
    }
};