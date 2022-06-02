func transpose(mat [][]int) [][]int {
    m,n:=len(mat),len(mat[0])
    res:=make([][]int,n)
    for i:=0;i<n;i+=1{
        res[i]=make([]int,m)
    }
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            res[j][i]=mat[i][j]
        }
    }
    return res
}