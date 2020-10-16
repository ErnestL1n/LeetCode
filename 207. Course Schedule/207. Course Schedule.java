//bfs
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph=buildGraph(prerequisites,numCourses);
        int[] degree=countInDegree(graph);
        for(int i=0;i<numCourses;++i){
            int j=0;
            for(;j<numCourses;++j)
                if(degree[j]==0)
                    break;
            if(j==numCourses)
                return false;
            degree[j]=-1;
            for(int d:graph.get(j))
                --degree[d];
        }
        return true;       
    }
    private List<List<Integer>> buildGraph(int[][] prerequisites,int numCourses){
        List<List<Integer>> g=new ArrayList<>();
        for(int i=0;i<numCourses;++i)
            g.add(new ArrayList());
        for(int i=0;i<prerequisites.length;++i)
            g.get(prerequisites[i][1]).add(prerequisites[i][0]);
        return g;
    }
    private int[] countInDegree(List<List<Integer>> graph){
        int[] degree=new int[graph.size()];
        for(var adj:graph)
            for(var d:adj)
                ++degree[d];
        return degree;
    }
}




//dfs
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean[] todo=new boolean[numCourses];
        boolean[] done=new boolean[numCourses];
        List<List<Integer>> graph=buildGraph(numCourses,prerequisites);
        for(int i=0;i<numCourses;++i)
            if(!done[i]&&!acyclic(graph,todo,done,i))
                return false;
        return true;
    }
    private List<List<Integer>> buildGraph(int numCourses,int[][] prerequisites){
        List<List<Integer>> g=new ArrayList<>();
        for(int i=0;i<numCourses;++i)
            g.add(new ArrayList());
        for(int i=0;i<prerequisites.length;++i)
            g.get(prerequisites[i][1]).add(prerequisites[i][0]);
        return g;
    }
    private boolean acyclic(List<List<Integer>> graph,boolean[] todo,boolean[] done,int node){
        if(todo[node])
            return false;
        if(done[node])
            return true;
        todo[node]=done[node]=true;
        for(int k:graph.get(node))
            if(!acyclic(graph,todo,done,k))
                return false;
        todo[node]=false;
        return true;
    }
}