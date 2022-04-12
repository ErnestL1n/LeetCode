class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int lives=neighbors(board,m,n,i,j);
                if(board[i][j]==1 and lives>=2 and lives<=3){
                    board[i][j]=3;
                }
                if(board[i][j]==0 and lives==3){
                    board[i][j]=2;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                board[i][j]>>=1;
            }
        }
    }
    int neighbors(vector<vector<int>>& board,int m,int n,int i,int j){
        int lives=0;
        for(int x=max(i-1,0);x<=min(i+1,m-1);++x){
            for(int y=max(j-1,0);y<=min(j+1,n-1);++y){
                lives+=board[x][y]&1;
            }
        }
        lives-=board[i][j]&1;
        return lives;
    }
};