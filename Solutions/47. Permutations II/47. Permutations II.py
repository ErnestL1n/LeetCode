class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def perm(nums,res,begin):
            if begin==len(nums):
                res.append(nums[:])
                return
            s=set()
            for i in range(begin,len(nums)):
                if nums[i] not in s:
                    nums[i],nums[begin]=nums[begin],nums[i]
                    perm(nums,res,begin+1)
                    nums[i],nums[begin]=nums[begin],nums[i]
                    s.add(nums[i])
            return
        res=[]
        perm(nums,res,0)
        return res