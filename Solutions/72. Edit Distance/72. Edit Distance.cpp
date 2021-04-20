class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1=word1.size(),sz2=word2.size();
        vector<vector<int>> dp(2,vector<int>(sz1+1));
        for(int i=0;i<=sz1;++i)
            dp[0][i]=i;
        for(int i=1;i<=sz2;++i)
            for(int j=0;j<=sz1;++j){
                if(j==0)
                    dp[i%2][j]=i;
                else if(word1[j-1]==word2[i-1])
                    dp[i%2][j]=dp[(i-1)%2][j-1];
                else
                    dp[i%2][j]=1+min(dp[(i-1)%2][j-1]
                                        ,min(dp[(i-1)%2][j],dp[(i%2)][j-1]));
            }
        return dp[sz2%2][sz1];
    }
};