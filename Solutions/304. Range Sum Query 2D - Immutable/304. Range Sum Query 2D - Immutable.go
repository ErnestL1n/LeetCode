type NumMatrix struct {
    sums [][]int
}


func Constructor(mat [][]int) NumMatrix {
    m,n:=len(mat),len(mat[0])
    sums:=make([][]int,m+1)
    for i:=0;i<=m;i+=1{
        sums[i]=make([]int,n+1)
    }
    for i:=1;i<=m;i+=1{
        for j:=1;j<=n;j+=1{
            sums[i][j]=mat[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]
        }
    }
    return NumMatrix{sums}
}


func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
    return this.sums[row2+1][col2+1]-this.sums[row2+1][col1]-this.sums[row1][col2+1]+this.sums[row1][col1]
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */