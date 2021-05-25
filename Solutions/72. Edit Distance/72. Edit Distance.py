class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        sz1,sz2=len(word1),len(word2)
        # dp[1] Nested lists =>wrong
        # dp1=[[0]*(sz1+1)]*2
        
        # two-dimensional array => right
        dp=[[0]*(sz1+1) for _ in range(2)]
        #print(dp1)
        print(dp)
        for i in range(sz1+1):
            dp[0][i]=i
        for i in range(1,sz2+1):
            for j in range(sz1+1):
                if j==0:
                    dp[i%2][j]=i
                elif word1[j-1]==word2[i-1]:
                    dp[i%2][j]=dp[(i-1)%2][j-1]
                else:
                    dp[i%2][j]=1+min(dp[(i-1)%2][j-1],dp[(i-1)%2][j],dp[(i%2)][j-1])
        return dp[sz2%2][sz1]