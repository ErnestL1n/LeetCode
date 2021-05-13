class Solution {
    public int smallestRangeI(int[] nums, int k) {
        int m_ax=nums[0],m_in=nums[0];
        for(int i=1;i<nums.length;++i){
            m_ax=Math.max(m_ax,nums[i]);
            m_in=Math.min(m_in,nums[i]);
        }
        if(m_ax-m_in-2*k>0){
            return m_ax-m_in-2*k;
        }else
            return 0;
    }
}