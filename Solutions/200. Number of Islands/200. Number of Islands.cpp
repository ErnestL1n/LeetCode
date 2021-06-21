//DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int res=0,m=g.size(),n=g[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]=='1')
                    res+=dfs(g,i,j);
        return res;
    }
    int dfs(vector<vector<char>>& g,int i,int j){
        int res=1,m=g.size(),n=g[0].size();
        if(i<0 or i>=m or j<0 or j>=n or g[i][j]=='0')
            return res;
        g[i][j]='0';
        dfs(g,i-1,j);
        dfs(g,i,j-1);
        dfs(g,i+1,j);
        dfs(g,i,j+1);
        return res;
    }
};

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int res=0,m=g.size(),n=g[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(g[i][j]=='0' or vis[i][j])
                    continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=true;
                bool isIsland=true;
                while(q.size()>0){
                    auto [x,y]=q.front();q.pop();
                    if(g[x][y]=='0')
                        isIsland=false;
                    for(const auto& [a,b]:dirs){
                        int r=x+a,c=y+b;
                        if(r<0 or c<0 or r>=m or c>=n or vis[r][c] or g[r][c]=='0')
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