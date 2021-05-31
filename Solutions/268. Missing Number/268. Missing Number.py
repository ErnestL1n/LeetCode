class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res,i=len(nums),0
        while i<len(nums):
            res+=i-nums[i]
            i+=1
        return res

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res,i=len(nums),0
        while i<len(nums):
            res^=nums[i]^i
            i+=1
        return res