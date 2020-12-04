func updateMatrix(matrix [][]int) [][]int {
    if len(matrix)==0 || len(matrix[0])==0{
        return matrix
    }
    queue:=make([][]int,0)
    for i:=range(matrix){
        for j:=range(matrix[i]){
            if matrix[i][j]==0{
                queue=append(queue,[]int{i,j})
            }else{
                matrix[i][j]=math.MaxInt16
            }
        }  
    }
    dirs:=[][]int{{-1,0},{1,0},{0,-1},{0,1}}
    for len(queue)>0{
        cell:=queue[0]
        i,j:=cell[0],cell[1]
        queue=queue[1:]
        for _,dir:=range(dirs){
            d1,d2:=dir[0],dir[1]
            r:=i+d1
            c:=j+d2
            if r<0 || r>=len(matrix) || c<0 || c>=len(matrix[0]) || matrix[r][c]<=1+matrix[i][j]{
                continue
            }
            queue=append(queue,[]int{r,c})
            matrix[r][c]=matrix[i][j]+1
        }
    }
    return matrix
}