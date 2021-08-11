class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        //res is initialized as all leading 1s
        int m=grid.size(),n=grid[0].size(),res=m*(1<<(n-1));
        for(int j=1;j<n;++j){
            // this column 1s
            int cnt_1s=0;
            //trick part ,if grid[i][0]==1 grid[i][j] must be 1 as well 
            for(int i=0;i<m;++i)
                cnt_1s+=grid[i][0]==grid[i][j];
            //if m=cnt_1s+cnt_0s , find which one is maximum
            res+=max(cnt_1s,m-cnt_1s)*(1<<(n-1-j));
        }
        return res;
    }
};