class Solution {
    public int maxSubArray(int[] nums) {
        int curr=Integer.MIN_VALUE,res=Integer.MIN_VALUE;
        for(int n:nums){
            curr=Math.max(curr,0)+n;
            res=Math.max(res,curr);
        }
        return res;
    }
}