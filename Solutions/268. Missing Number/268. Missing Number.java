class Solution {
    public int missingNumber(int[] nums) {
        int res,i;
        for(i=0,res=nums.length;i<nums.length;++i)
            res+=i-nums[i];
        return res;
    }
}