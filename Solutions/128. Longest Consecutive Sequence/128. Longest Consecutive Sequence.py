#HashSet implementation
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums=set(nums)
        best=0
        for x in nums:
            if x-1 not in nums:
                y=x+1
                while y in nums:
                    y+=1
                best=max(best,y-x)
        return best
        
        
#Sort
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums.sort()
        longseq,currseq=1,1
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:
                if nums[i]==nums[i-1]+1:
                    currseq+=1
                else:
                    longseq=max(longseq,currseq)
                    currseq=1
        return max(longseq,currseq)
 
 
#Union Find