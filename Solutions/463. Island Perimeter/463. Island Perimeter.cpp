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