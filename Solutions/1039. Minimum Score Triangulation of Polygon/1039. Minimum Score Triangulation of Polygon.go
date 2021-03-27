//top down
func minScoreTriangulation(values []int) int {
    dp:=make([][]int,50)
    for i,_:=range(dp){dp[i]=make([]int,50)}
    return foo(&dp,&values,0,len(values)-1)
}
func foo(dp *[][]int,values *[]int,i,j int) int{
    if j-i<=1{
        return 0
    }
    if (*dp)[i][j]==0{
        (*dp)[i][j]=math.MaxInt32
        for k:=i+1;k<j;k+=1{
            (*dp)[i][j]=min((*dp)[i][j],foo(dp,values,i,k)+foo(dp,values,k,j)+(*values)[i]*(*values)[k]*(*values)[j])
        }
    }
    return (*dp)[i][j]
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}

//buttom up
func minScoreTriangulation(values []int) int {
    dp:=make([][]int,50)
    for i,_:=range(dp){dp[i]=make([]int,50)}
    for i:=len(values)-1;i>=0;i-=1{
        for j:=i+1;j<len(values);j+=1{
            for k:=i+1;k<j;k+=1{
                if(dp[i][j]==0){
                    dp[i][j]=math.MaxInt32
                }
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[j]*values[k])
            }
        }
    }
    return dp[0][len(values)-1]
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}