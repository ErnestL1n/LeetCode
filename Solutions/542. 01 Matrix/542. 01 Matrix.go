//bfs approach
func updateMatrix(matrix [][]int) [][]int {
    if len(matrix)==0 || len(matrix[0])==0{
        return matrix
    }
    queue:=make([][]int,0)
    for i:=range(matrix){
        for j:=range(matrix[0]){
            if matrix[i][j]==0{
                queue=append(queue,[]int{i,j})
            }else{
                matrix[i][j]=math.MaxInt16
            }
        }
    }
    dirs:=[][]int{{-1,0},{1,0},{0,1},{0,-1}}
    for len(queue)>0{
        i,j:=queue[0][0],queue[0][1]
        queue=queue[1:]
        for _,dir:=range(dirs){
            r,c:=dir[0]+i,dir[1]+j
            if r<0 || r>=len(matrix) || c<0 || c>=len(matrix[0]) || matrix[r][c]<=1+matrix[i][j]{continue}
            // if update from matrix[i][j]
            queue=append(queue,[]int{r,c})
            matrix[r][c]=1+matrix[i][j]
        }
    }
    return matrix
}



//dp

func updateMatrix(matrix [][]int) [][]int {
    for i,row:=range matrix{
        for j,val:=range row{
            if val!=0{
                top,left:=math.MaxInt16,math.MaxInt16
                if i>0{
                    top=matrix[i-1][j]+1
                }
                if j>0{
                    left=matrix[i][j-1]+1
                }
                matrix[i][j]=min(top,left)
            }
        }
    }
    for i:=len(matrix)-1;i>=0;i-=1{
        for j:=len(matrix[0])-1;j>=0;j-=1{
            if matrix[i][j]!=0{
                down,right:=math.MaxInt16,math.MaxInt16
                if i<len(matrix)-1{
                    down=matrix[i+1][j]+1
                }
                if j<len(matrix[0])-1{
                    right=matrix[i][j+1]+1
                }
                matrix[i][j]=min(min(down,right),matrix[i][j])
            }
        }
    }
    return matrix
}
func min(a,b int)int{
    if a>b{
        return b
    }
    return a
}