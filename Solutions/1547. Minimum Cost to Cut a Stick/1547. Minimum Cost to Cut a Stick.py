# Top down
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        dp=[[0]*102 for _ in range(102)]
        def dfs(cuts,i,j):
            if j-i<=1:
                return 0
            if not dp[i][j]:
                dp[i][j]=sys.maxsize
                for k in range(i+1,j):
                    dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dfs(cuts,i,k)+dfs(cuts,k,j))
            return dp[i][j]
        cuts.append(0)
        cuts.append(n)
        cuts.sort()
        return dfs(cuts,0,len(cuts)-1)

# Bottom Up
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.append(0)
        cuts.append(n)
        cuts.sort()
        size=len(cuts)
        dp=[[0]*size for _ in range(size)]
        for i in range(size-1,-1,-1):
            for j in range(i+1,size):
                for k in range(i+1,j):
                    dp[i][j]=min(sys.maxsize if dp[i][j]==0 else dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j])
        
        return dp[0][size-1]