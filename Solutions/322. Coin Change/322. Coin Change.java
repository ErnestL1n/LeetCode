class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp=new int[amount+1];
        Arrays.fill(dp,amount+9487);
        dp[0]=0;
        for(int i=1;i<=amount;++i)
            for(var c:coins)
                if(i>=c)
                    dp[i]=Math.min(dp[i],1+dp[i-c]);
        return dp[amount]==amount+9487?-1:dp[amount];
    }
}