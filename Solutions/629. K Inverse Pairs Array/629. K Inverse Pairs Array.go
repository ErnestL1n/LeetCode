func kInversePairs(N int, K int) int {
    dp:=make([][]int,2)
    for i:=0;i<2;i+=1{
        dp[i]=make([]int,1001)
    }
    dp[0][0]=1
    for n:=1;n<=N;n+=1{
        for k:=0;k<=K;k+=1{
            if k>0{
                dp[n%2][k]=(dp[(n-1)%2][k]+dp[n%2][k-1])%1000000007
            }else{
                dp[n%2][k]=dp[(n-1)%2][k]%1000000007
            }
            if k>=n{
                dp[n%2][k]=(1000000007+dp[n%2][k]-dp[(n-1)%2][k-n])%1000000007
            }
        }
    }
    return dp[N%2][K];
}