func countNegatives(grid [][]int) int {
    m,n,res:=len(grid),len(grid[0]),0
    r,c:=m-1,0
    for r>=0 && c<n{
        if grid[r][c]<0{
            res+=n-c
            r-=1
        }else{
            c+=1
        }
    }
    return res
}