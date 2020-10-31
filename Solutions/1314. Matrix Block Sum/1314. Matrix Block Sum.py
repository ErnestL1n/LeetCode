class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m,n=len(mat),len(mat[0])
        dp=[[0]*(n+1)for _ in range(m+1)]
        for i in range(m):
            for j in range (n):
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j]+mat[i][j]
        res=[[0]*(n)for _ in range(m)]
        for i in range(m):
            for j in range(n):
                r_lo,c_lo,r_hi,c_hi=max(0,i-K),max(0,j-K),min(m,i+K+1),min(n,j+K+1)
                res[i][j]=dp[r_hi][c_hi]-dp[r_hi][c_lo]-dp[r_lo][c_hi]+dp[r_lo][c_lo]
        return res;