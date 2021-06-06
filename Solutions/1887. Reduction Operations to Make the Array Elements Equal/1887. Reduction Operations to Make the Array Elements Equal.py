class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        res,sz=0,len(nums)
        for i in range(sz-1,0,-1):
            if nums[i]!=nums[i-1]:
                res+=sz-i
        return res
        