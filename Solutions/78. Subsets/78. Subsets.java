class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> tmp=new ArrayList<>();
        foo(nums,res,tmp,0);
        return res;
    }
    private void foo(int[] nums,List<List<Integer>> res,List<Integer> tmp,int begin){
        res.add(new ArrayList<>(tmp));
        for(int i=begin;i<nums.length;++i){
            tmp.add(nums[i]);
            foo(nums,res,tmp,i+1);
            tmp.remove(tmp.size()-1);
        }
    }
}