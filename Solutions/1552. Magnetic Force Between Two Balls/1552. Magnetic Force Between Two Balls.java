class Solution {
    public int maxDistance(int[] p, int m) {
        Arrays.sort(p);
        int lo=0,hi=p[p.length-1]-p[0];
        while(lo<=hi){
            int dis=(lo+hi)/2;
            if(foo(p,dis,m))
                lo=dis+1;
            else
                hi=dis-1;
        }
        return hi;
    }
    private boolean foo(int[] pos,int dis,int m){
        int begin=-1,used=0;
        for(int p:pos){
            if(begin<=p){
                begin=p+dis;
                ++used;
            }
        }
        return used>=m;
    }
}