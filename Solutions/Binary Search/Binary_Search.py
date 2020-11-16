class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left,right=0,len(nums)-1
        while left<=right:
            mid=int((left+right)/2)
            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                left=mid+1
            else:
                right=mid-1
        return -1
		



#hashmap version(not good in this case)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        m={}
        for i,n in enumerate(nums):
            m[n]=i
        if target in m:
            return m[target]
        else:
            return -1
			

