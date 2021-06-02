class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res,l,r,n=nums[0],0,0,len(nums)
        for i in range(n):
            if l==0:
                l=1
            l*=nums[i]
            if r==0:
                r=1
            r*=nums[n-1-i]
            res=max(res,max(l,r))
        return res