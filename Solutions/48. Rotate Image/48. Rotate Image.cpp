class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        reverse(mat.begin(),mat.end());
        for(int i=0;i<mat.size();++i){
            for(int j=i+1;j<mat[0].size();++j){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};