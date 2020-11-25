//Kruskal v1
class Solution {
    private int find(int[] ds,int i){
        if(ds[i]<0)
            return i;
        ds[i]=find(ds,ds[i]);
        return ds[i];
    }
    public int minCostConnectPoints(int[][] points) {
        int n=points.length,res=0;
        int[] ds=new int[n];
        Arrays.fill(ds,-1);
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        for(int i=0;i<n-1;++i)
            for(int j=0;j<n;++j){
                int dist=Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]);
                pq.offer(new int[]{dist,i,j});
            }
        while(!pq.isEmpty()){
            int[] e=pq.poll();
            e[1]=find(ds,e[1]);
            e[2]=find(ds,e[2]);
            if(e[1]!=e[2]){
                res+=e[0];
                ds[e[1]]+=ds[e[2]];
                ds[e[2]]=e[1];
                if(ds[e[1]]==-n)
                    break;
            }
        }
        return res;
    }
}





// Kruskal v2
class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n=points.length;
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        for(int i=0;i<n-1;++i)
            for(int j=i+1;j<n;++j){
                int dist=Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]);
                pq.offer(new int[]{dist,i,j});
            }
        int res=0;
        Union un=new Union(n);
        while(!un.United()&&!pq.isEmpty()){
            int[] edge=pq.poll();
            int p1=edge[1];
            int p2=edge[2];
            if(un.Unite(p1,p2))
                res+=edge[0];
        }
        return res;
    }
    private class Union{
        int components;
        int[] component;
        Union(){};
        Union(int n){
            components=n;
            component=new int[n+1];
            for(int i=0;i<=n;++i)
                component[i]=i;
        }
        int Find(int a){
            if(component[a]!=a)
                component[a]=Find(component[a]);
            return component[a];
        }
        boolean Unite(int a,int b){
            if(Find(a)==Find(b))
                return false;
            --components;
            component[Find(a)]=b;
            return true;
        }
        boolean United(){return components==1;}
    }
}


//Prim's
class Solution {
    public int minCostConnectPoints(int[][] points) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[0]-b[0]);  //min heap
        int res=0,connected=0,i=0,n=points.length;
        boolean[] visited=new boolean[n];
        while(++connected<n){
            visited[i]=true;
            for(int j=1;j<n;++j)
                if(!visited[j])
                    pq.offer(new int[]{Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]),j});
            while(visited[pq.peek()[1]])
                pq.poll();
            int[] curr=pq.poll();
            res+=curr[0];
            i=curr[1];
        }
        return res;
    }
}

//optimal Prim's for Complete Graph
class Solution {
    public int minCostConnectPoints(int[][] points) {
        int res=0,n=points.length,i=n-1,connected=0;
        int[] min_d=new int[n];
        Arrays.fill(min_d,10000000);
        while(++connected<n){
            min_d[i]=Integer.MAX_VALUE;
            int min_j=i;
            for(int j=0;j<n;++j){
                if(min_d[j]!=Integer.MAX_VALUE){
                    min_d[j]=Math.min(min_d[j],Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]));
                    min_j=min_d[j]<min_d[min_j]?j:min_j;
                }
            }
            res+=min_d[min_j];
            i=min_j;
        }
        return res;
    }
}

