class Solution {
    public int waysToMakeFair(int[] nums) {
        int[] l=new int[2],r=new int[2];
        int res=0;
        for(int i=0;i<nums.length;++i)
            r[i%2]+=nums[i];
        for(int i=0;i<nums.length;++i){
            r[i%2]-=nums[i];
            if(r[0]+l[1]==r[1]+l[0])
                ++res;
            l[i%2]+=nums[i];
        }
        return res;
    }
}