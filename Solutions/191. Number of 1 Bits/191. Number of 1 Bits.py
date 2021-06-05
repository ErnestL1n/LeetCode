class Solution:
    def hammingWeight(self, n: int) -> int:
        res=0
        while n>0:
            t=n&1
            if t==1:
                res+=1
            n>>=1
        return res

class Solution:
    def hammingWeight(self, n: int) -> int:
        res=0
        while n>0:
            res+=1
            n&=(n-1)
        return res        