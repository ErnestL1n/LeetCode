class Solution:
    def maximalSquare(self, m: List[List[str]]) -> int:
        edge,dp=0,[[0]*len(m[0]) for _ in range(len(m))]
        for i in range(len(m)):
            for j in range(len(m[0])):
                if m[i][j]=='1' and i>0 and j>0:
                    dp[i][j]=1+min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])
                else:
                    dp[i][j]=int(m[i][j])
                edge=max(edge,dp[i][j])
        return edge*edge