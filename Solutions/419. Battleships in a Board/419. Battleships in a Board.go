func countBattleships(board [][]byte) int {
    m,n,res:=len(board),len(board[0]),0
    for i:=0;i<m;i+=1{
        for j:=0;j<n;j+=1{
            if board[i][j]=='.'{
                continue
            }
            if i>0 && board[i-1][j]=='X'{
                continue
            }
            if j>0 && board[i][j-1]=='X'{
                continue
            }
            res+=1
        }
    }
    return res
}