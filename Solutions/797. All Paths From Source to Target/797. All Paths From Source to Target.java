class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] g) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> path=new ArrayList<>();
        path.add(0);
        dfs(g,res,path,0);
        return res;
    }
    private void dfs(int[][] g,List<List<Integer>> res,List<Integer> path,int node){
        if(node==g.length-1)
            res.add(new ArrayList<Integer>(path));
        for(var i:g[node]){
            path.add(i);
            dfs(g,res,path,i);
            path.remove(path.size()-1);
        }
    }
}