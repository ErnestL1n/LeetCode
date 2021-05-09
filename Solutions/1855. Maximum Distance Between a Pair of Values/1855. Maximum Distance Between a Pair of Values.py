class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        def bs(x,nums):
            l,r=0,len(nums)-1
            while l<=r:
                mid=(l+r)//2
                if x>nums[mid]:
                    r=mid-1
                else:
                    l=mid+1
            return r
        res=0
        for i in range(len(nums1)):
            tmp=bs(nums1[i],nums2)
            if tmp<i:
                continue
            if res<tmp-i:
                res=tmp-i
        return res

        
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        i,j,n1,n2,res=0,0,len(nums1),len(nums2),0
        while i<n1 and j<n2:
            if nums1[i]>nums2[j]:
                i+=1
            else:
                res=max(res,j-i)
                j+=1
        return res