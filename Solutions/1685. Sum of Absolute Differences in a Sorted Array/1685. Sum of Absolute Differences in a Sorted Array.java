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

// reduce (extra)space version
class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int leftsum=0,rightsum=sum(nums),n=nums.length;
        int[] res=new int[n];
        for(int i=0;i<n;++i){
            res[i]=i*nums[i]-leftsum+rightsum-nums[i]*(n-i);
            leftsum+=nums[i];
            rightsum-=nums[i];
        }
        return res;
    }
    private int sum(int[] nums){
        int s=0;
        for(int i=0;i<nums.length;++i)
            s+=nums[i];
        return s;
    }
}