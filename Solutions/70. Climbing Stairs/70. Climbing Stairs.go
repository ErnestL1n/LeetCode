//TLE
func climbStairs(n int) int {
    return cb(n)
}
func cb(n int) int {
    if n<=1{
        return 1
    }
    return cb(n-1)+cb(n-2)
}

//memo
func climbStairs(n int) int {
    dp:=make([]int,n+1)
    dp[0]=1
    dp[1]=1
    for i:=2;i<=n;i+=1{
        dp[i]=dp[i-1]+dp[i-2]
    }
    return dp[n]
}

//memo opt
func climbStairs(n int) int {
    dp:=make([]int,2)
    dp[0]=1
    dp[1]=1
    for i:=2;i<=n;i+=1{
        dp[i%2]=dp[(i-1)%2]+dp[(i-2)%2]
    }
    return dp[n%2]
}