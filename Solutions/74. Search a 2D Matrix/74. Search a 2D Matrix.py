class Solution:
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:
        m,n=len(mat),len(mat[0])
        l,r=0,m*n-1
        while l<=r:
            mid=(l+r)//2
            if mat[mid//n][mid%n]==target:
                return True
            if mat[mid//n][mid%n]<target:
                l=mid+1
            else:
                r=mid-1
        return False