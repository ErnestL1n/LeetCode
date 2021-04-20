class Solution {
    public int minDistance(String word1, String word2) {
        int sz1=word1.length(),sz2=word2.length();
        int[][] dp=new int[2][sz1+1];
        for(int i=0;i<=sz1;++i)
            dp[0][i]=i;
        for(int i=1;i<=sz2;++i)
            for(int j=0;j<=sz1;++j){
                if(j==0)
                    dp[i%2][j]=i;
                else if(word1.charAt(j-1)==word2.charAt(i-1))
                    dp[i%2][j]=dp[(i-1)%2][j-1];
                else
                    dp[i%2][j]=1+Math.min(dp[(i-1)%2][j-1]
                                        ,Math.min(dp[(i-1)%2][j],dp[(i%2)][j-1]));
            }
        return dp[sz2%2][sz1];
    }
}