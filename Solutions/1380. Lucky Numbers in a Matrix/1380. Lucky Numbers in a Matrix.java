class Solution {
    public List<Integer> luckyNumbers (int[][] mat) {
        int m=mat.length,n=mat[0].length;
        int maxMin=Integer.MIN_VALUE;
        for(int i=0;i<m;++i){
            int Min=Integer.MAX_VALUE;
            for(int j=0;j<n;++j)
                Min=Math.min(Min,mat[i][j]);
            maxMin=Math.max(maxMin,Min);
        }
        int minMax=Integer.MAX_VALUE;
        for(int j=0;j<n;++j){
            int Max=Integer.MIN_VALUE;
            for(int i=0;i<m;++i)
                Max=Math.max(Max,mat[i][j]);
            minMax=Math.min(minMax,Max);
        }
        var res=new ArrayList<Integer>();
        if(minMax!=maxMin)
            return res;
        res.add(minMax);
        return res;
    }
}