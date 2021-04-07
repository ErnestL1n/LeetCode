class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        int[] skh=new int[m],skv=new int[n];
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                skh[i]=Math.max(skh[i],grid[i][j]);
                skv[j]=Math.max(skv[j],grid[i][j]);
            }
        int res=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                res+=Math.min(skh[i],skv[j])-grid[i][j];
        return res;
    }
}