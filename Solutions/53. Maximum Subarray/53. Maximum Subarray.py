class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr,res=float('-inf'),float('-inf')
        for n in nums:
            curr=max(curr,0)+n
            res=max(res,curr)
        return res