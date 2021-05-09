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