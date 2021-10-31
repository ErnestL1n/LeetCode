class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0,res=0;
        queue<pair<int,int>> que;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2){
                    que.push({i,j});
                }else if(grid[i][j]==1){
                    ++cnt;
                }
            }
        }
        if(cnt==0){
            return 0;
        }
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(que.size()){
            int size=que.size();
            for(int sz=0;sz<size;++sz){
                int i=que.front().first,j=que.front().second;
                que.pop();
                for(int k=0;k<4;++k){
                    int x=i+dirs[k].first,y=j+dirs[k].second;
                    if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==0 or grid[x][y]==2){
                        continue;
                    }
                    grid[x][y]=2;
                    que.push({x,y});
                    --cnt;
                }
            }
            ++res;
        }
        return cnt==0?res-1:-1;
    }
};