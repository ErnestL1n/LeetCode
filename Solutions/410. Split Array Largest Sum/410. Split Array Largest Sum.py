class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def count(nums,m,target_sum):
            cnt,s=1,0
            for n in nums:
                s+=n
                if s>target_sum:
                    s=n
                    cnt+=1
                    if cnt>m:
                        return False
            return True
        if m==1:
            return sum(nums)
        lo,hi=max(nums),sum(nums)
        while lo<hi:
            mid=(lo+hi)//2
            if count(nums,m,mid):
                hi=mid
            else:
                lo=mid+1
        return lo
