class Solution {
    public int[] decompressRLElist(int[] nums) {
        int size=0;
        for(int i=0;i<nums.length;i+=2)
            size+=nums[i];
        int[] res=new int[size];
        size=0;
        for(int i=0,j=1;i<nums.length;i+=2,j+=2)
            while(nums[i]-->0)
                res[size++]=nums[j];
        return res;
    }
}