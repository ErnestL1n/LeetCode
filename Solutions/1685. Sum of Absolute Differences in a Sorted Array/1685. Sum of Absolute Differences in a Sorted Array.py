class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n=len(nums)
        prefix,res=[0]*(n+1),[0]*n
        for i in range(n):
            prefix[i+1]=prefix[i]+nums[i]
        for i in range(n):
            res[i]=i*nums[i]-prefix[i]+(prefix[n]-prefix[i]-(n-i)*nums[i])
        return res
        
        

# reduce (extra)space version
class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n,leftsum,rightsum=len(nums),0,sum(nums)
        res=[0]*n
        for i in range(n):
            res[i]=i*nums[i]-leftsum+(rightsum-(n-i)*nums[i])
            leftsum+=nums[i]
            rightsum-=nums[i]
        return res