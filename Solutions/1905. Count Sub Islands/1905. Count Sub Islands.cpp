//BFS
class Solution {
public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m=g1.size(),n=g1[0].size(),res=0;
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(vis[i][j] or g2[i][j]==0)
                    continue;
                vis[i][j]=true;
                queue<pair<int,int>> q;
                q.push({i,j});
                bool isIsland=true;
                while(q.size()>0){
                    auto [a,b]=q.front();q.pop();
                    if(g1[a][b]==0)
                        isIsland=false;
                    for(const auto& [x,y]:dirs){
                        int r=a+x,c=b+y;
                        if(r<0 or c<0 or r>=m or c>=n or vis[r][c] or g2[r][c]==0)
                            continue;
                        vis[r][c]=true;
                        q.push({r,c});
                    }
                }
                if(isIsland)
                    ++res;
            }
        return res;
    }
};