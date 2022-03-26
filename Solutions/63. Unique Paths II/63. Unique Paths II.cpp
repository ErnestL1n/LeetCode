class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0]=1;
        for(auto& row:obstacleGrid){
            for(int j=0;j<n;++j){
                if(row[j]==1){
                    dp[j]=0;
                }else if(j>0){
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};