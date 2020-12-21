class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        i,j,tmp,res=0,0,0,0
        s=set()
        while i<len(nums) and j<len(nums):
            if nums[i] not in s:
                s.add(nums[i])
                tmp+=nums[i]
                i+=1
                res=max(res,tmp)
            else:
                s.remove(nums[j])
                tmp-=nums[j]
                j+=1
        return res