class Solution {
    public int numSubarrayBoundedMax(int[] nums, int L, int R) {
        int res=0,prev=-1,dp=0;
        for(int i=0;i<nums.length;++i){
            if(nums[i]<L && i>0)
                res+=dp;
            if(nums[i]>R){
                dp=0;
                prev=i;
            }
            if(L<=nums[i] && nums[i]<=R){
                dp=i-prev;
                res+=dp;
            }
        }
        return res;
    }
}