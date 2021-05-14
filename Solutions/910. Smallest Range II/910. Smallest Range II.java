class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int res=nums[nums.length-1]-nums[0],right=nums[nums.length-1]-k,left=nums[0]+k;
        for(int i=0;i<nums.length-1;++i){
            int m_ax=Math.max(right,nums[i]+k);
            int m_in=Math.min(left,nums[i+1]-k);
            res=Math.min(res,m_ax-m_in);
        }
        return res;
    }
}