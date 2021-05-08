class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> path=new ArrayList<>();
        Arrays.sort(candidates);
        foo(candidates,target,res,path,0);
        return res;
    }
    private void foo(int[] c,int t,List<List<Integer>> res,List<Integer> path,int begin){
        if(t<=0){
            if(t==0){
                res.add(new ArrayList<Integer>(path));
                return;
            }
            return;
        }
        for(int i=begin;i<c.length;++i){
            if(i>begin && c[i]==c[i-1])
                continue;
            path.add(c[i]);
            foo(c,t-c[i],res,path,i+1);
            path.remove(path.size()-1);
        }
    }
}