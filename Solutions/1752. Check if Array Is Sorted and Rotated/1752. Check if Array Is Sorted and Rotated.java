class Solution {
    public boolean check(int[] nums) {
        int cnt=0,n=nums.length;
        for(int i=0;i<n;++i)
            if(nums[i]>nums[(i+1)%n] && ++cnt>1)
                return false;
        return true;
    }
}