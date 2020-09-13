class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        Arrays.sort(edges,(a,b)->b[0]-a[0]);
        int addEdges=0;
        Union Bob=new Union(n);
        Union Alice=new Union(n);
        for(int[] edge:edges){
            int type=edge[0];
            int start=edge[1];
            int end=edge[2];
            switch(type){
                case 3:
                    if(Bob.Unite(start,end)|Alice.Unite(start,end))
                        ++addEdges;
                    break;
                case 2:
                    if(Bob.Unite(start,end))
                        ++addEdges;
                    break;
                case 1:
                    if(Alice.Unite(start,end))
                        ++addEdges;
                    break;               
            }
        }
        return (Alice.United()&&Bob.United())?edges.length-addEdges:-1;
    }
    private class Union{
    int distinctcomponents;
    int[] components;
    Union(){};
    public Union(int n){
        components=new int[n+1];
        distinctcomponents=n;
        for(int i=0;i<=n;++i)
            components[i]=i;
    }
    private int Find(int a){
        if(components[a]!=a)
            components[a]=Find(components[a]);
        return components[a];
    }
    private boolean Unite(int a,int b){
        if(Find(a)==Find(b))
            return false;
        components[Find(a)]=b;
        --distinctcomponents;
        return true;
    }
    private boolean United(){
        return distinctcomponents==1;
    }
    
}
}
