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










//simple version bfs,faster
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> G=new ArrayList<>();
        int[] degree=new int[numCourses];
        for(int i=0;i<numCourses;++i)
            G.add(new ArrayList());
        for(var k:prerequisites){
            G.get(k[1]).add(k[0]);
            ++degree[k[0]];
        }  
        Queue<Integer> q=new LinkedList<>();
        for(int i=0;i<numCourses;++i)
            if(degree[i]==0)
                q.offer(i);
        int cnt=0;
        while(!q.isEmpty()){
            int k=q.poll();
            ++cnt;
            for(int d:G.get(k))
                if(--degree[d]==0)
                    q.offer(d);
        }
        return cnt==numCourses;
    }
}




//simple version dfs,faster
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        state=new int[numCourses];
        List<List<Integer>> G=new ArrayList<>();
        for(int i=0;i<numCourses;++i){
            G.add(new ArrayList());
            state[i]=-1;
        }
        for(var p:prerequisites)
            G.get(p[1]).add(p[0]);
        for(int i=0;i<numCourses;++i)
            if(dfs(G,i)==false)
                return false;
        return true;
    }
    private int[] state;
    //-1:unvisited,0:visiting,1:visited
    private boolean dfs(List<List<Integer>> p,int u){
        if(state[u]!=-1)
            return state[u]==1;
        state[u]=0;
        for(int k:p.get(u))
            if(dfs(p,k)==false)
                return false;
        state[u]=1;
        return true;
    }
}