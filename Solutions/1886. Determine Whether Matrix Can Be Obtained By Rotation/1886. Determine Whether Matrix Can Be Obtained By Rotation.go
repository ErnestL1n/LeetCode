func findRotation(mat [][]int, target [][]int) bool {
    c:=make([]bool,4)
    for i,_:=range(c){c[i]=true}
    n:=len(mat)
    for i,_:=range(mat){
        for j,_:=range(mat[0]){
            if mat[i][j]!=target[i][j]{
                c[0]=false
            }
            if mat[i][j]!=target[n-1-j][i]{
                c[1]=false
            }
            if mat[i][j]!=target[j][n-1-i]{
                c[2]=false
            }
            if mat[i][j]!=target[n-1-i][n-1-j]{
                c[3]=false
            }
        }
    }
    return c[0] || c[1] || c[2] ||c[3]
}