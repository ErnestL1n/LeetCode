//Dijkstra
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        List<List<int[]>> graph=new ArrayList<>();
        for(int i=0;i<=N;++i)
            graph.add(new ArrayList<>());
        for(int[] time:times){
            graph.get(time[0]).add(new int[]{time[1],time[2]});
        } 
        boolean[] visited=new boolean[N+1];
        int[] d=new int[N+1];
        Arrays.fill(d,Integer.MAX_VALUE);
        d[0]=d[K]=0;
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->(a[0]-b[0]));
        pq.offer(new int[]{0,K});
        while(!pq.isEmpty()){
            int[] curr=pq.poll();
            int dis=curr[0],node=curr[1];
            if(visited[node])
                continue;          
            for(var to:graph.get(node)){
                int v=to[0],w=to[1];
                if(dis+w<d[v]){
                    d[v]=dis+w;
                    pq.offer(new int[]{d[v],v});
                } 
            }    
            visited[node]=true;
        }
        int res=Integer.MIN_VALUE;
        for(int i=0;i<d.length;++i)
            res=res<d[i]?d[i]:res;
        return res==Integer.MAX_VALUE?-1:res;
    }
}






//Bellman Ford
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int[] dist=new int[N+1];
        for(int i=0;i<=N;++i)
            dist[i]=Integer.MAX_VALUE;
        dist[0]=dist[K]=0;
        for(int i=0;i<N;++i)
            for(var t:times){
                int u=t[0], v=t[1], w=t[2];
                if(dist[u]!=Integer.MAX_VALUE&&dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }
        int res=0;
        for(int i=1;i<=N;++i){
            res=Math.max(res,dist[i]);
        }
        return res==Integer.MAX_VALUE?-1:res;
    }
}