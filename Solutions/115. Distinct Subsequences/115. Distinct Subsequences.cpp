class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<unsigned>> dp(m+1,vector<unsigned>(n+1));
        for(int j=0;j<=n;++j)
            dp[0][j]=1;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(t[i]==s[j])
                    dp[i+1][j+1]=dp[i][j]+dp[i+1][j];
                else
                    dp[i+1][j+1]=dp[i+1][j];
            }
        return dp[m][n];
    }
};