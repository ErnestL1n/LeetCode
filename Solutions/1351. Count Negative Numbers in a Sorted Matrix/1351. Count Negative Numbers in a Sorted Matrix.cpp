class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0,m=grid.size(),n=grid[0].size();
        int r=m-1,c=0;
        while(r>=0 && c<n){
            if(grid[r][c]<0){
                res+=n-c;
                --r;
            }else
                ++c;
        }
        return res;
    }
};