class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        m={0:0}
        cnt,res=0,0
        for idx,n in enumerate(nums,start=1):
            if n==0:
                cnt-=1
            else:
                cnt+=1
            if cnt in m:
                res=max(res,idx-m[cnt])
            else:
                m[cnt]=idx
        return res   