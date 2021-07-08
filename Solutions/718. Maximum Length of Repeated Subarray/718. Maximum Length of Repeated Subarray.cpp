class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),res=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        //dp[i][j] is the length of longest common subarray ending with nums[i-1] "and" nums[j-1]
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
            }
        return res;
    }
};