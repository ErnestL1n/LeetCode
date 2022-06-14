func minDistance(word1 string, word2 string) int {
    m,n:=len(word1),len(word2)
    dp:=make([][]int,m+1)
    for i:=0;i<=m;i+=1{
        dp[i]=make([]int,n+1)
    }
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
            if word1[i]==word2[j]{
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1)
            }
        }
    }
    return m+n-2*dp[m][n]
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}