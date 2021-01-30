class Solution {
    public boolean searchMatrix(int[][] mat, int target) {
        int m=mat.length,n=mat[0].length;
        int l=0,r=m*n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mat[mid/n][mid%n]==target)
                return true;
            if(mat[mid/n][mid%n]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
}