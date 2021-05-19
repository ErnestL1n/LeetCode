class Solution {
    public int climbStairs(int n) {
        return cb(n);
    }
    private int cb(int n){
        if(n<=1)
            return 1;
        return cb(n-1)+cb(n-2);
    }
}

class Solution {
    public int climbStairs(int n) {
        int[] dp=new int[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
}

class Solution {
    public int climbStairs(int n) {
        int[] dp=new int[2];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i)
            dp[i%2]=dp[(i-1)%2]+dp[(i-2)%2];
        return dp[n%2];
    }
}