func shiftGrid(grid [][]int, k int) [][]int {
    m,n:=len(grid),len(grid[0])
    st:=m*n-k%(m*n)
    var res [][]int
    for i:=st;i<st+m*n;i+=1{
        j:=i%(m*n)
        r,c:=j/n,j%n
        if (i-st)%n==0{
            res=append(res,[]int{})
        }
        res[len(res)-1]=append(res[len(res)-1],grid[r][c])
    }
    return res
}