func maximalSquare(m [][]byte) int {
    dp:=make([][]int,len(m))
    for i,_:=range(dp){dp[i]=make([]int,len(m[0]))}
    edge:=0
    for i:=0;i<len(m);i+=1{
        for j:=0;j<len(m[0]);j+=1{
            if m[i][j]=='1' && i>0 && j>0{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1
            }else{
                dp[i][j]=int(m[i][j]-'0')
            }
            edge=max(edge,dp[i][j])
        }
    }
    return edge*edge
}

func min(i,j int)int{
    if i<j{
        return i
    }
    return j
}
func max(i,j int)int{
    if i<j{
        return j
    }
    return i
}