var dp [200][200]int
var res,m,n int

func longestIncreasingPath(mat [][]int) int {
    res,m,n=0,len(mat),len(mat[0])
    for i:=0;i<200;i+=1{
        for j:=0;j<200;j+=1{
            dp[i][j]=0
        }
    }
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            res=max(res,dfs(&mat,i,j,-1))
        }
    }
    return res
}

func dfs(mat *[][]int,i,j,prev int) int{
    if i<0 || j<0 || i>=m || j>=n || (*mat)[i][j]<=prev{
        return 0
    }
    if dp[i][j]!=0{
        return dp[i][j]
    }
    dp[i][j]=1+max(max(dfs(mat,i+1,j,(*mat)[i][j]),dfs(mat,i-1,j,(*mat)[i][j])),max(dfs(mat,i,j+1,(*mat)[i][j]),dfs(mat,i,j-1,(*mat)[i][j])))
    return dp[i][j]
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}
