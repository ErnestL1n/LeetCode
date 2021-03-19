class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int res=0;
        for(int i=0;i<mat.size();++i)
            for(int j=0;j<mat[0].size();++j){
                if(mat[i][j]>0&&i>0&&j>0)
                    mat[i][j]+=min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j]))+1;
                res+=mat[i][j];
            }
        return res;
    }
};