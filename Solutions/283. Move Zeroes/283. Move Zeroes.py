class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j=0
        for n in nums:
            if n!=0:
                nums[j]=n
                j+=1
        print
        while j<len(nums):
            nums[j]=0
            j+=1
        
        