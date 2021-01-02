func diagonalSum(mat [][]int) int {
    n,sum:=len(mat),0
    for i,_:=range(mat){
        sum+=mat[i][i]+mat[i][n-i-1]
    }
    if n%2==1{
        return sum-mat[n/2][n/2]
    }
    return sum
}