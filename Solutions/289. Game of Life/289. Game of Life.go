func gameOfLife(board [][]int)  {
    m,n:=len(board),len(board[0])
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            lives:=neighbors(board,m,n,i,j)
            if board[i][j]==1 && lives>=2 && lives<=3{
                board[i][j]=3
            }
            if board[i][j]==0 && lives==3{
                board[i][j]=2
            }
        }
    }
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            board[i][j]>>=1
        }
    }
}

func neighbors(board [][]int,m,n,i,j int)int{
    lives:=0
    for x:=max(0,i-1);x<=min(i+1,m-1);x+=1{
        for y:=max(0,j-1);y<=min(j+1,n-1);y+=1{
            lives+=board[x][y]&1
        }
    }
    lives-=board[i][j]&1
    return lives
}

func max(i,j int)int{
    if i>j{
        return i
    }
    return j
}

func min(i,j int)int{
    if i<j{
        return i
    }
    return j
}