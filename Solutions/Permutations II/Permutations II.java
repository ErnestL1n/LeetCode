class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        help(res,0,nums);
        return res;
    }
    private void help(List<List<Integer>> res,int begin,int[] nums){
        if(begin==nums.length){
            var temp=new ArrayList<Integer>();
            for(int i=0;i<nums.length;++i)
                temp.add(nums[i]);
            res.add(temp);
            return;
        }
        var s=new HashSet<Integer>();
        for(int i=begin;i<nums.length;++i){
            if(!s.contains(nums[i])){
                swap(nums,begin,i);
                help(res,begin+1,nums);
                swap(nums,begin,i);
                s.add(nums[i]);
            }
        }
        return;
    }
    private void swap(int[] nums,int a,int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
}
