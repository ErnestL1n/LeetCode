#tricky version
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        res=0
        n=len(arr)
        for i,a in enumerate(arr):
            res+=((i+1)*(n-i)+1)//2*a
        return res



#prefix sum
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n,res=len(arr),0
        prefix=[0]*(n+1)
        for i,a in enumerate(arr):
            prefix[i+1]=prefix[i]+a
        for i in range(0,n):
            for j in range(i+1,n+1,2):
                res+=prefix[j]-prefix[i]
        return res;