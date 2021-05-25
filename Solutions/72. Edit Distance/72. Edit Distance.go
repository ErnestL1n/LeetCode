func minDistance(word1 string, word2 string) int {
    sz1,sz2:=len(word1),len(word2)
    dp:=make([][]int,2)
    for i,_:=range(dp){dp[i]=make([]int,sz1+1)}
    for i:=0;i<=sz1;i+=1{
        dp[0][i]=i
    }
    for i:=1;i<=sz2;i+=1{
        for j:=0;j<=sz1;j+=1{
            if j==0{
                dp[i%2][j]=i
            }else if word1[j-1]==word2[i-1]{
                dp[i%2][j]=dp[(i-1)%2][j-1]
            }else{
                dp[i%2][j]=1+min(dp[(i-1)%2][j-1],min(dp[(i-1)%2][j],dp[i%2][j-1]))
            }
        }
    }
    return dp[sz2%2][sz1]
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}