class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int res=0;
        for(int i=0;i<g.size();++i)
            for(int j=0;j<g[0].size();++j){
                if(g[i][j]){
                    res+=4;
                    if(i&&g[i-1][j])res-=2;
                    if(j&&g[i][j-1])res-=2;
                }
            }
        return res;
    }
};

// 2021/10/4
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0;
        vector<array<int,2>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1)
                    cnt+=4;
                for(int k=0;k<4;++k){
                    int x=dirs[k][0]+i;
                    int y=dirs[k][1]+j;
                    if(x<0 or y<0 or x>=m or y>=n){
                        continue;
                    }else{
                        if(grid[x][y]==1 and grid[i][j]==1)
                            cnt-=1;
                    }
                }
            }
        }
        return cnt;
    }
};