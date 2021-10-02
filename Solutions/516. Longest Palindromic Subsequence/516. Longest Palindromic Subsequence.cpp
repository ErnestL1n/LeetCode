class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int len=1;len<=n;++len){
            for(int i=0;i<=n-len;++i){
                int j=i+len-1;
                if(i==j){
                    dp[i][j]=1;
                    continue;
                }
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};