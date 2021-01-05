class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<int> res;
        for(int i=0;i<col;++i){
            int i1=i,i2;
            for(int j=0;j<row;++j){
                i2=i1+grid[j][i1];
                if(i2<0 || i2 >=col || grid[j][i1]!=grid[j][i2]){
                    i1=-1;
                    break;
                }
                i1=i2;
            }
            res.push_back(i1);
        }
        return res;
    }
};