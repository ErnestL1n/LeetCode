class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def valid(nums,mid,m):
            cnt,total=1,0
            for num in nums:
                total+=num
                if total>mid:
                    total=num
                    cnt+=1
                    if cnt>m:
                        return False
            return True
        Max,s=max(nums),sum(nums)
        if m==1:
            return s
        l,r=Max,s
        while l<=r:
            mid=(l+r)//2
            if valid(nums,mid,m):
                r=mid-1
            else:
                l=mid+1
        return l
        