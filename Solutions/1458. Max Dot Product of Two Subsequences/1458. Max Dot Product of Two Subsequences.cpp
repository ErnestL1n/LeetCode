typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        VVI dp(m,VI(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                dp[i][j]=nums1[i]*nums2[j];
                if(i&&j)dp[i][j]+=max(0,dp[i-1][j-1]);
                if(i)dp[i][j]=max(dp[i-1][j],dp[i][j]);
                if(j)dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        return dp[m-1][n-1];
    }
};