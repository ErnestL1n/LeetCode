class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int lo=0,hi=m*n-1;
        while(lo<=hi){
            int mid=lo+hi>>1;
            if(mat[mid/n][mid%n]==target){
                return true;
            }
            if(mat[mid/n][mid%n]<target){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return false;
    }
};