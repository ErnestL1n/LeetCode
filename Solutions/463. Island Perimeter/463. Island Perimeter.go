func islandPerimeter(g [][]int) int {
    res:=0
    for i:=0;i<len(g);i+=1{
        for j:=0;j<len(g[0]);j+=1{
            if g[i][j]==1{
                res+=4
                if i>0 && g[i-1][j]==1{
                    res-=2
                }
                if j>0 && g[i][j-1]==1{
                    res-=2
                }
            }
        }
    }
    return res
}