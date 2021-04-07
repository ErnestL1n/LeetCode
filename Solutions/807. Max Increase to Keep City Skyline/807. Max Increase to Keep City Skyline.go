func maxIncreaseKeepingSkyline(grid [][]int) int {
    m,n,res:=len(grid),len(grid[0]),0
    skh,skv:=make([]int,m),make([]int,n)
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            skh[i]=max(skh[i],grid[i][j])
            skv[j]=max(skv[j],grid[i][j])
        }
    }
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            res+=min(skh[i],skv[j])-grid[i][j]
        }
    }
    return res
}
func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}