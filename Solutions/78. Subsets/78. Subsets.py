class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def foo(res,tmp,begin):
            res.append(tmp)
            for i in range(begin,len(nums)):
                tmp.append(nums[i])
                foo(res,tmp,begin+1)
                tmp.pop()
        res,tmp=[[]],[]
        foo(nums,res,tmp)
        return res