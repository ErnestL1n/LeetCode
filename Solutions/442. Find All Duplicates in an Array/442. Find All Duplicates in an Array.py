class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        cnt=[0]*(len(nums)+1)
        res=[]
        for n in nums:
            cnt[n]+=1
        for i in range(1,len(nums)+1):
            if cnt[i]==2:
                res.append(i)
        return res