class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        l,r,res=[0,0],[0,0],0
        for i in range(len(nums)):
            r[i%2]+=nums[i]
        for i in range(len(nums)):
            r[i%2]-=nums[i]
            x,y=r[0]+l[1],r[1]+l[0]
            if x==y:
                res+=1
            l[i%2]+=nums[i]
        return res