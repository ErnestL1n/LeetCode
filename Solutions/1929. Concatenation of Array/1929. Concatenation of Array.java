class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] res=new int[nums.length*2];
        for(int i=0;i<nums.length;++i)
            res[i+nums.length]=res[i]=nums[i];
        return res;
    }
}