class Solution:
    def climbStairs(self, n: int) -> int:
        def cb(n):
            if n<=1:
                return 1
            return cb(n-1)+cb(n-2)
        return cb(n)
        
class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[0]*(n+1)
        dp[0]=dp[1]=1
        for i in range(2,n+1):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[n]

class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[0]*2
        dp[0]=dp[1]=1
        for i in range(2,n+1):
            dp[i%2]=dp[(i-1)%2]+dp[(i-2)%2]
        return dp[n%2]