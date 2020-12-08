class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def perm(nums:List[int],res:List[List[int]],begin:int):
            if begin==len(nums):
                res.append(nums[:])
                return
            for i in range(begin,len(nums)):
                nums[i],nums[begin]=nums[begin],nums[i]
                perm(nums,res,begin+1)
                nums[i],nums[begin]=nums[begin],nums[i]
            return
        res=[]
        perm(nums,res,0)
        return res
                