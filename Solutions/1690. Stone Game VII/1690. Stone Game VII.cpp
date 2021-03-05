class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size(),prefix[n+1];
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+stones[i];
        for(int len=2;len<=n;++len)
            for(int i=0;i<=n-len;++i){
                int j=i+len-1;
                dp[i][j]=max((prefix[j+1]-prefix[i+1])-dp[i+1][j],
                            (prefix[j]-prefix[i])-dp[i][j-1]);
            }
        return dp[0][n-1];
    }
};