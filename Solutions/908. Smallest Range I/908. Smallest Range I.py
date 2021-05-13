class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        m_ax,m_in=max(nums),min(nums)
        return m_ax-m_in-2*k if m_ax-m_in-2*k>0 else 0