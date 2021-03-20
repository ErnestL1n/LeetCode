class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int edge=0;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(i>0&&j>0&&mat[i][j]=='1')
                    dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
                else
                    dp[i][j]=mat[i][j]=='1'?1:0;
                edge=max(edge,dp[i][j]);
            }
        return pow(edge,2);
    }
};