class Solution:
    def minMoves(self, nums: List[int]) -> int:
        s=0
        for i in range(len(nums)):
            s+=nums[i]
        return s-min(nums)*len(nums)