func stoneGameII(piles []int) int {
    n:=len(piles)
    dp:=make([][]int,n+1)
    for i,_:=range(dp){dp[i]=make([]int,n+1)}
    sufsum:=make([]int,n+1)
    for i:=n-1;i>=0;i-=1{
        sufsum[i]=sufsum[i+1]+piles[i]
    }
    for i:=0;i<=n;i+=1{
        dp[i][n]=sufsum[i]
    }
    for i:=n-1;i>=0;i-=1{
        for j:=n-1;j>=1;j-=1{
            for X:=1;X<=2*j&&i+X<=n;X+=1{
                dp[i][j]=max(dp[i][j],sufsum[i]-dp[i+X][max(j,X)]);
            }
        }                
    }
    return dp[0][1];
}
func max(i,j int)int{
    if(i>j){
        return i
    }
    return j
}