class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n=nums.length;
        int[] prefix=new int[n+1];
        int[] res=new int[n];
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+nums[i];
        for(int i=0;i<n;++i)
            res[i]=nums[i]*i-prefix[i]+(prefix[n]-prefix[i]-(n-i)*nums[i]);
        return res;
    }
}