class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n,res=len(mat),0
        for i in range(n):
            res+=mat[i][i]+mat[i][n-i-1]
        return res-mat[n//2][n//2] if n%2==1 else res