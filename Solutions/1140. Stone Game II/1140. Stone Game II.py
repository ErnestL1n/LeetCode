class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n=len(piles)
        dp=[[0]*(n+1) for _ in range(n+1)]
        sufsum=[0]*(n+1)
        for i in range(n-1,-1,-1):
            sufsum[i]=sufsum[i+1]+piles[i]
        for i in range(n+1):
            dp[i][n]=sufsum[i]
        for i in range(n-1,-1,-1):
            for j in range(n-1,0,-1):
                X=1
                while X<=2*j and i+X<=n:
                    dp[i][j]=max(dp[i][j],sufsum[i]-dp[i+X][max(j,X)])
                    X+=1
        return dp[0][1]