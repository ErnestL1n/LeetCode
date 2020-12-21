class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int i=0,j=0,res=0,tmp=0;
        var s=new HashSet<Integer>();
        while(i<nums.length&&j<nums.length){
            if(!s.contains(nums[i])){
                s.add(nums[i]);
                tmp+=nums[i++];
                res=Math.max(res,tmp);
            }else{
                s.remove(nums[j]);
                tmp-=nums[j++];
            }
        }
        return res;
    }
}