class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return nums.size()==1?nums[0]:nums[1]>nums[0]?nums[1]:nums[0];
        return max(foo(nums,0,n-2),foo(nums,1,n-1));
    }
    int foo(vector<int>& nums,int st,int ed){
        int n=ed-st+1;
        vector<int> dp(n);
        dp[0]=nums[st],dp[1]=max(nums[st],nums[st+1]);
        for(int i=st+2;i<=ed;++i){
            dp[i-st]=max(dp[i-st-1],dp[i-st-2]+nums[i]);
        }
        return dp[n-1];
    }
};