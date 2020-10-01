//recursive
//idea:https://leetcode.wang/leetCode-46-Permutations.html
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        help(res,nums,0);
        return res;
    }
    private void help(List<List<Integer>> res,int[] nums,int begin){
        if(begin==nums.length){
            var temp=new ArrayList<Integer>();
            for(int i=0;i<nums.length;++i)
                temp.add(nums[i]);
            res.add(temp);
            return;
        }
        for(int i=begin;i<nums.length;++i){
            swap(begin,i,nums);
            help(res,nums,begin+1);
            swap(begin,i,nums);
        }
    }
    private void swap(int a,int b,int[] nums){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
}