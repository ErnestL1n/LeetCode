# We have counts of a + e + i + o + u = n
#Therefore, we can use combination with repetition formula to solve it as:
#answer = H(5, n) = C(5 + n - 1, n) = C(4 + n, n) = C(n + 4, 4) = (n+4) * (n+3) * (n+2) * (n+1) / 4!

class Solution:
    def countVowelStrings(self, n: int) -> int:
        return int((n+4)*(n+3)*(n+2)*(n+1)/24);

#accumulate
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp=[0]+[1]*5
        for i in range(1,n+1):
            for k in range(1,6):
                dp[k]+=dp[k-1]
        return dp[5]