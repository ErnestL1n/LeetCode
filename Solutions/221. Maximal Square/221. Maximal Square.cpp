class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        vector<vector<int>> dp(m.size(),vector<int>(m[0].size()));
        int res=0;
        for(int i=0;i<m.size();++i)
            for(int j=0;j<m[0].size();++j){
                if(m[i][j]-'0' && i>0 && j>0)
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else
                    dp[i][j]=m[i][j]-'0';
                res=max(res,dp[i][j]);
            }
        return res*res;
    }
};