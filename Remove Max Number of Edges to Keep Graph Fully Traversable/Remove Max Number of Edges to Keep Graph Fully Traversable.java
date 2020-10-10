//optimal version
//Complexity Analysis

//Time: O(m), where m is the number of edges. 
//We go through all edges 3 times. The complexity of the find operation is O(𝛼(n)) as we use both rank and path compression. 
//𝛼(n) can be considered a constant for all practical purposes.
//Memory: O(n) for a disjoined set.

class Solution {
    private int find(int[] ds,int i){
        if(ds[i]<0)
            return i;
        ds[i]=find(ds,ds[i]);
        return ds[i];
    }
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        int[] ds_both=new int[n+1];
        int used=0;
        Arrays.fill(ds_both,-1);
        for(int type=3;type>=1;--type){
            int[] ds_one=new int[n+1];
            for(int i=0;i<=n;++i)
                ds_one[i]=ds_both[i];
            int[] ds=type==3?ds_both:ds_one;
            for(var e:edges){
                if(e[0]==type){
                    int i=find(ds,e[1]),j=find(ds,e[2]);
                    if(i!=j){
                        ++used;
                        ds[i]+=ds[j];
                        ds[j]=i;
                    }
                }
            }
            if(type!=3&&ds[find(ds,n)]!=-n)
                return -1;
        }
        return edges.length-used;
    }
}


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

