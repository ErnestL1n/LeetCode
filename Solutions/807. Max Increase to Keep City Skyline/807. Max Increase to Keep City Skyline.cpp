class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> skh(m),skv(n);
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                skh[i]=max(skh[i],grid[i][j]);
                skv[j]=max(skv[j],grid[i][j]);
            }
        int res=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                res+=min(skh[i],skv[j])-grid[i][j];
        return res;
    }
};