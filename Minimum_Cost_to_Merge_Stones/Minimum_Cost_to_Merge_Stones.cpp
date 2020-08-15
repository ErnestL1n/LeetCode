class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n=stones.size();
        if((n-1)%(K-1)!=0)return -1;
        vector<int> prefix(n+1);
        for(int i=1;i<=n;++i)
            prefix[i]=prefix[i-1]+stones[i-1];
        vector<vector<int>> dp(n,vector<int>(n));
        for(int len=K;len<=n;++len)
            for(int i=0,j=i+len-1;j<n;++i,++j){
                dp[i][j]=INT_MAX;
                for(int mid=i;mid<j;mid+=K-1)
                    dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                if((j-i)%(K-1)==0)
                    dp[i][j]+=prefix[j+1]-prefix[i];
            }
        return dp[0][n-1];
    }
};