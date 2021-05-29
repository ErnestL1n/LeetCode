class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        vector<int> sufsum(n+1);
        for(int i=n-1;i>=0;--i)
            sufsum[i]=sufsum[i+1]+piles[i];
        for(int i=0;i<=n;++i)
            dp[i][n]=sufsum[i];
        for(int i=n-1;i>=0;--i)
            for(int j=n-1;j>=1;--j)
                for(int X=1;X<=2*j and i+X<=n;X++)
                    dp[i][j]=max(dp[i][j],sufsum[i]-dp[i+X][max(j,X)]);
        return dp[0][1];
    }
};