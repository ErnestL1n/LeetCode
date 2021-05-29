class Solution {
    public int stoneGameII(int[] piles) {
        int n=piles.length;
        int[][] dp=new int[n+1][n+1];
        int[] sufsum=new int[n+1];
        for(int i=n-1;i>=0;--i)
            sufsum[i]=sufsum[i+1]+piles[i];
        for(int i=0;i<=n;++i)
            dp[i][n]=sufsum[i];
        for(int i=n-1;i>=0;--i)
            for(int j=n-1;j>=1;--j)
                for(int X=1;X<=2*j&&i+X<=n;++X)
                    dp[i][j]=Math.max(dp[i][j],sufsum[i]-dp[i+X][Math.max(j,X)]);
        return dp[0][1];
    }
}