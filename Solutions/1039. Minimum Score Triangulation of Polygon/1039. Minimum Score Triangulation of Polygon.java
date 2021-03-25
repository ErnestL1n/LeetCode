//top down
class Solution {
    int[][] dp=new int[50][50];
    public int minScoreTriangulation(int[] values) {
        return foo(values,0,values.length-1);
    }
    private int foo(int[] values,int i,int j){
        if(j-i<=1)
            return 0;
        if(dp[i][j]==0){
            dp[i][j]=Integer.MAX_VALUE;
            for(int k=i+1;k<j;++k)
                dp[i][j]=Math.min(dp[i][j],values[i]*values[j]*values[k]+foo(values,i,k)+foo(values,k,j));
        }
        return dp[i][j];
    }
}

//buttom up
class Solution {
    public int minScoreTriangulation(int[] values) {
        int dp[][]=new int[50][50];
        for(int i=values.length-1;i>=0;--i)
            for(int j=i+1;j<values.length;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=Math.min(dp[i][j]==0?Integer.MAX_VALUE:dp[i][j],
                                dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
        return dp[0][values.length-1];
    }
}