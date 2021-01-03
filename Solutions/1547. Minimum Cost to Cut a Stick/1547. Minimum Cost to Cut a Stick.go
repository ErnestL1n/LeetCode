//Top Down

import (
    "math"
    "sort"
)
func minCost(n int, cuts []int) int {
    dp:=make([][]int,102)
    for i,_:=range(dp){dp[i]=make([]int,102)}
    cuts=append(cuts,0)
    cuts=append(cuts,n)
    sort.Ints(cuts)
    return dfs(&dp,&cuts,0,len(cuts)-1)
}

func dfs(dp *[][]int,cuts *[]int,i,j int)int{
    if j-i<=1{
        return 0
    }
    if (*dp)[i][j]==0{
        (*dp)[i][j]=math.MaxInt32
        for k:=i+1;k<j;k+=1{
            (*dp)[i][j]=min((*dp)[i][j],(*cuts)[j]-(*cuts)[i]+dfs(dp,cuts,i,k)+dfs(dp,cuts,k,j))
        }
    }
    return (*dp)[i][j]
}

func min(i,j int)int{
    if i<j{
        return i
    }
    return j
}


//Bottom Up

import (
    "math"
    "sort"
)
func minCost(n int, cuts []int) int {
    cuts=append(cuts,0)
    cuts=append(cuts,n)
    sort.Ints(cuts)
    size:=len(cuts)
    dp:=make([][]int,size)
    for i,_:=range(dp){dp[i]=make([]int,size)}
    for i:=size-1;i>=0;i-=1{
        for j:=i+1;j<size;j+=1{
            for k:=i+1;k<j;k+=1{
                if dp[i][j]==0{
                    dp[i][j]=math.MaxInt32
                }
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i])
            }
        }
    }
    return dp[0][len(cuts)-1]
}

func min(i,j int)int{
    if i<j{
        return i
    }
    return j
}