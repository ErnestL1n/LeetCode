class Solution {
    public int islandPerimeter(int[][] g) {
        int res=0;
        for(int i=0;i<g.length;++i)
            for(int j=0;j<g[0].length;++j){
                if(g[i][j]==1){
                    res+=4;
                    if(i>0 && g[i-1][j]==1)
                        res-=2;
                    if(j>0 && g[i][j-1]==1)
                        res-=2;
                }
            }
        return res;
    }
}