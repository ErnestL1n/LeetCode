class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def foo(nums,res,tmp,begin):
            res.append(tmp.copy())
            for i in range(begin,len(nums)):
                tmp.append(nums[i])
                foo(nums,res,tmp,i+1)
                tmp.pop()
        res,tmp=[],[]
        foo(nums,res,tmp,0)
        return res