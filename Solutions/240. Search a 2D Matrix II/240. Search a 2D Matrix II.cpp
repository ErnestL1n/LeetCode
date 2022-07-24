class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size(),r=0,c=n-1;
        while(r<m and c>=0){
            if(mat[r][c]==target){
                return true;
            }
            mat[r][c]>target?--c:++r;
        }
        return false;
    }
};