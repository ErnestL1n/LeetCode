class Solution {
    public int minMoves(int[] nums) {
        int sum=0,m_in=Integer.MAX_VALUE;
        for(int i=0;i<nums.length;++i){
            sum+=nums[i];
            m_in=Math.min(m_in,nums[i]);
        }
        return sum-m_in*nums.length;
    }
}