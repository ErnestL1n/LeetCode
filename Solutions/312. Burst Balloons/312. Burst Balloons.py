#   buttom up method
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        arr=[]
        arr.append(1)
        for num in nums:
            if num>0:
                arr.append(num)
        arr.append(1)
        n=len(arr)
        dp=[[0]*n for _ in range(n)]
        for i in range(n-1,-1,-1):
            for j in range(i+1,n,1):
                for k in range(i+1,j):
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k])
        return dp[0][n-1]
        
        
        

        
#   top down recursive method with memoization, TLE in leetcode OJ (python3)
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp=[[0]*502 for _ in range(502)]
        def foo(arr,i,j):
            if(j-i<=1):
                return 0
            if not dp[i][j]:
                for k in range(i+1,j):
                    dp[i][j]=max(dp[i][j],arr[i]*arr[k]*arr[j]+foo(arr,i,k)+foo(arr,k,j))
            return dp[i][j]
        arr=[]
        arr.append(1)
        for num in nums:
            if num>0:
                arr.append(num)
        arr.append(1)
        return foo(arr,0,len(arr)-1)
            
            
            