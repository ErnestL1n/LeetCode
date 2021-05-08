class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> path=new ArrayList<>();
        foo(candidates,target,path,res,0);
        return res;
    }
    private void foo(int[] c,int t,List<Integer> path,List<List<Integer>> res,int begin){
        if(t<=0){
            if(t==0){
                res.add(new ArrayList<>(path));
                return;
            }
            return;
        }
        for(int i=begin;i<c.length;++i){
            path.add(c[i]);
            foo(c,t-c[i],path,res,i);
            path.remove(path.size()-1);
        }
    }
}