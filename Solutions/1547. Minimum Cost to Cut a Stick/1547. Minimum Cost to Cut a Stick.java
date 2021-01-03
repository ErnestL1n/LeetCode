//Top Down
class Solution {
    public int minCost(int n, int[] cuts) {
        var c = new ArrayList<Integer>();
        for (int cut : cuts)
            c.add(cut);
        c.addAll(Arrays.asList(0, n));
        Collections.sort(c);
        return dfs(c,0,c.size()-1);
    }
    private int[][] dp=new int[102][102];
    private int dfs(ArrayList<Integer> cuts,int i,int j){
        if(j-i<=1)return 0;
        if(dp[i][j]==0){
            dp[i][j]=Integer.MAX_VALUE;
            for(int k=i+1;k<j;++k)
                dp[i][j]=Math.min(dp[i][j],
                                 cuts.get(j)-cuts.get(i)+dfs(cuts,i,k)+dfs(cuts,k,j));
        }
        return dp[i][j];
    }
}


//Bottom Up
class Solution {
    public int minCost(int n, int[] cuts) {
        var cutarray=new ArrayList<Integer>();
        for(int cut:cuts)
            cutarray.add(cut);
        cutarray.addAll(Arrays.asList(0,n));
        Collections.sort(cutarray);
        int size=cutarray.size();
        int[][] dp=new int[size][size];
        for(int i=size-1;i>=0;--i)
            for(int j=i+1;j<size;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=Math.min(dp[i][j]==0?Integer.MAX_VALUE:dp[i][j],
                                     cutarray.get(j)-cutarray.get(i)+dp[i][k]+dp[k][j]);
        return dp[0][size-1];
    }
}
