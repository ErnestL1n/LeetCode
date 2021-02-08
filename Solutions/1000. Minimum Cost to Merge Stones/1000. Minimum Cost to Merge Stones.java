class Solution {
    public int mergeStones(int[] stones, int K) {
        int n=stones.length;
        if((n-1)%(K-1)!=0)return -1;
        int[] prefix=new int[n+1];
        for(int i=1;i<=n;++i)
            prefix[i]=prefix[i-1]+stones[i-1];
        int[][] dp=new int[n][n];
        for(int len=K;len<=n;++len)
            for(int i=0,j=i+len-1;j<n;++i,++j){
                dp[i][j]=Integer.MAX_VALUE;
                for(int mid=i;mid<j;mid+=K-1)
                    dp[i][j]=Math.min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                if((j-i)%(K-1)==0)
                    dp[i][j]+=prefix[j+1]-prefix[i];
            }
        return dp[0][n-1];
    }
}