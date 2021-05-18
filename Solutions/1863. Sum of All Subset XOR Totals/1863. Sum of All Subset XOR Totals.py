class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def subset(nums,s,tmp,begin):
            s.append(tmp.copy())
            for i in range(begin,len(nums)):
                tmp.append(nums[i])
                subset(nums,s,tmp,i+1)
                tmp.pop()
            return 
        s,tmp,res=[],[],0
        subset(nums,s,tmp,0)
        for x in s:
            tmp=0
            for n in x:
                tmp^=n
            res+=tmp
        return res
        
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res,l=0,len(nums)
        for n in nums:
            res|=n
        res*=pow(2,l-1)
        return res