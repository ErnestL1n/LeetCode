class Solution {
public:
    int dp[200][200]={};
    int res,m,n;
    int longestIncreasingPath(vector<vector<int>>& mat) {
        res=0,m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                res=max(res,dfs(mat,i,j,-1));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& mat,int i,int j,int prev){
        if(i<0 or j<0 or i>=m or j>=n or mat[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        return dp[i][j]=1+max({dfs(mat,i+1,j,mat[i][j]),
                              dfs(mat,i-1,j,mat[i][j]),
                              dfs(mat,i,j+1,mat[i][j]),
                              dfs(mat,i,j-1,mat[i][j])});
    }
};