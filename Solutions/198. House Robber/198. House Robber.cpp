// idea:https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
// TLE naive version
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums,nums.size()-1);
    }
    int rob(vector<int>& nums,int i){
        if(i<0)
            return 0;
        return max(nums[i]+rob(nums,i-2),rob(nums,i-1));
    }
};

//top down version Recursive + memo
class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return rob(nums,n-1);
    }
    int rob(vector<int>& nums,int i){
        if(i<0)
            return 0;
        if(dp[i]>=0)
            return dp[i];
        return dp[i]=max(rob(nums,i-1),rob(nums,i-2)+nums[i]);
    }
};

//bottom up version Iterative + memo
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        // dp[i]=max(dp[i-1],dp[i-2]+nums[i]) ,i>=2
        // dp[0]=0,dp[1]=nums[0]
        dp[0]=0,dp[1]=nums[0];
        for(int i=2;i<=nums.size();++i){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};



//O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int f=0,s=0;
        for(int n:nums){
            int tmp=f;
            f=max(f,s+n);
            s=tmp;
        }
        return f;
    }
};