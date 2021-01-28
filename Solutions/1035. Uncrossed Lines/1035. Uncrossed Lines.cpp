typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        VVI dp(m,VI(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                dp[i][j]=A[i]==B[j];
                if(i&&j)dp[i][j]+=max(dp[i-1][j-1],0);
                if(i)dp[i][j]=max(dp[i-1][j],dp[i][j]);
                if(j)dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        return dp[m-1][n-1];
    }
};