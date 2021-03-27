//top down
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        dp=[[0]*50 for _ in range(50)]
        def foo(values,i,j):
            if j-i<=1:
                return 0
            if not dp[i][j]:
                dp[i][j]=sys.maxsize
                for k in range(i,j+1):
                    dp[i][j]=min(dp[i][j],values[i]*values[k]*values[j]+foo(values,i,k)+foo(values,k,j))  
            return dp[i][j]
        return foo(values,0,len(values)-1)

//buttom up
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        dp=[[0]*50 for _ in range(50)]
        for i in range(len(values)-1,-1,-1):
            for j in range(i+1,len(values)):
                for k in range(i+1,j):
                    if not dp[i][j]:
                        dp[i][j]=sys.maxsize
                    dp[i][j]=min(dp[i][k]+dp[k][j]+values[i]*values[k]*values[j],dp[i][j])
        return dp[0][len(values)-1]     