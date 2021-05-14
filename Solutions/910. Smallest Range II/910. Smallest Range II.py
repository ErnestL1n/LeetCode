class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        res,right,left=nums[len(nums)-1]-nums[0],nums[len(nums)-1]-k,nums[0]+k,
        for i in range(0,len(nums));
            m_ax=max(right,nums[i]+k)
            m_in=min(left,nums[i+1]-k)
            res=min(res,m_ax-m_in)
        return res