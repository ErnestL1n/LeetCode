class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<short>> dp(2,vector<short>(1+(n1>n2?n1:n2)));
        for(int i=1;i<=n1;++i)
            for(int j=1;j<=n2;++j){
                if(s1[i-1]==s2[j-1])
                    dp[i%2][j]=1+dp[(i-1)%2][j-1];
                else
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        return dp[n1%2][n2];
    }
};