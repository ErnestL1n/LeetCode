func coinChange(coins []int, amount int) int {
    dp:=make([]int,amount+1)
    for i:=0;i<=amount;i+=1{
        dp[i]=1+amount
    }
    dp[0]=0
    for i:=1;i<=amount;i+=1{
        for _,c:=range(coins){
            if c<=i{
                dp[i]=min(dp[i],dp[i-c]+1)
            }
        }
    }
    if dp[amount]>amount{
        return -1
    }
    return dp[amount]
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}