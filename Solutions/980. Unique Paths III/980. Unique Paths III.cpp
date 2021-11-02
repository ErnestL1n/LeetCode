class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // why cnt=1 ?
        // Because the starting square grid[i][j] == 1 is counted 
        // besides the squares with a value of 0.
        int m=grid.size(),n=grid[0].size(),cnt=1,res=0;
        int sx,sy;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    ++cnt;
                }else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        function<void(int,int)> dfs=[&](int x,int y){
            if(x<0 or y<0 or x>=m or y>=n or grid[x][y]<0){
                return;
            }
            if(grid[x][y]==2){
                if(cnt==0){
                    ++res;
                }
                return;
            }
            grid[x][y]=-1;
            --cnt;
            dfs(x,y+1);
            dfs(x,y-1);
            dfs(x+1,y);
            dfs(x-1,y);
            grid[x][y]=0;
            ++cnt;
        };
        dfs(sx,sy);
        return res;
    }
};