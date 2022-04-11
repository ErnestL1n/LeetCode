class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int st=m*n-k%(m*n);
        vector<vector<int>> res;
        for(int i=st;i<m*n+st;++i){
            int j=i%(m*n),r=j/n,c=j%n;
            if((i-st)%n==0){
                res.push_back({});
            }
            res.back().push_back(grid[r][c]);
        }
        return res;
    }
};