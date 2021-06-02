class Solution {
    public int maxProduct(int[] nums) {
        int res=nums[0],l=0,r=0,n=nums.length;
        for(int i=0;i<n;++i){
            l=(l!=0?l:1)*nums[i];
            r=(r!=0?r:1)*nums[n-i-1];
            res=Math.max(res,Math.max(l,r));
        }
        return res;
    }
}