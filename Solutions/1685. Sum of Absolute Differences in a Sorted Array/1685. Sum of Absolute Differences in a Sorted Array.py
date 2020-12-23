class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n=len(nums)
        prefix,res=[0]*(n+1),[0]*n
        for i in range(n):
            prefix[i+1]=prefix[i]+nums[i]
        for i in range(n):
            res[i]=i*nums[i]-prefix[i]+(prefix[n]-prefix[i]-(n-i)*nums[i])
        return res