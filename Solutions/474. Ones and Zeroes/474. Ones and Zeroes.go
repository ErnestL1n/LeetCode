func findMaxForm(strs []string, m int, n int) int {
    dp:=make([][]int,m+1)
    for i:=0;i<=m;i+=1{
        dp[i]=make([]int,n+1)
    }
    var zcnt,ocnt int
    for _,s:=range strs{
        zcnt,ocnt=0,0
        for _,c:=range s{
            if c=='0'{
                zcnt+=1
            }else{
                ocnt+=1
            }
        }
        for i:=m;i>=zcnt;i-=1{
            for j:=n;j>=ocnt;j-=1{
                dp[i][j]=max(dp[i][j],1+dp[i-zcnt][j-ocnt])
            }
        }
    }
    return dp[m][n]
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}