func coinChange(coins []int, amount int) int {
    dp:=make([]int,amount+1)
    for i:=0;i<=amount;i+=1{
        dp[i]=amount+9487
    }
    dp[0]=0
    for i:=1;i<=amount;i+=1{
        for _,c:=range(coins){
            if i>=c{
                dp[i]=min(dp[i],1+dp[i-c])
            }
        }
    }
    if dp[amount]==amount+9487{
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