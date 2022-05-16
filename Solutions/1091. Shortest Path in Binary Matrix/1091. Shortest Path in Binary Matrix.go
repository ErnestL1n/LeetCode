func shortestPathBinaryMatrix(grid [][]int) int {
    var q [][2]int
    steps:=0
    q=append(q,[2]int{0,0})
    for len(q)>0{
        steps+=1
        var q1 [][2]int
        for len(q)>0{
            cur:=q[0];q=q[1:]
            if cur[0]>=0 && cur[1]>=0 && cur[0]<len(grid) && cur[1]<len(grid) && grid[cur[0]][cur[1]]==0{
                grid[cur[0]][cur[1]]=1
                if cur[0]==len(grid)-1 && cur[1]==len(grid)-1{
                    return steps
                }
                for i:=-1;i<2;i+=1{
                    for j:=-1;j<2;j+=1{
                        if i!=0 || j!=0{
                            q1=append(q1,[2]int{cur[0]+i,cur[1]+j})
                        }
                    }
                }
            }
        }
        q,q1=q1,q
    }
    return -1
}