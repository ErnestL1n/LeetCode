class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], L: int, R: int) -> int:
        res,prev=0,-1
        dp=0
        for i in range(len(nums)):
            if nums[i]<L and i>0:
                res+=dp
            if nums[i]>R:
                dp=0
                prev=i
            if L<=nums[i] and nums[i]<=R:
                dp=i-prev
                res+=dp
        return res