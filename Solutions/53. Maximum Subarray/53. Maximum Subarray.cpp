//2021.9.22
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        //dp[i]=maximum subarray(1~i)
        //dp[i]=dp[i-1]>0?dp[i-1]+nums[i]:nums[i]
        vector<int> dp(n+1);
        for(int i=1;i<=n;++i){
            dp[i]=dp[i-1]>0?dp[i-1]+nums[i-1]:nums[i-1];
            res=max(res,dp[i]);
        }
        return res;
    }
};

//space opt
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int prev=0,cur=0,res=INT_MIN;
        for(int i=0;i<n;++i){
            cur=prev>0?prev+nums[i]:nums[i];
            res=max(res,cur);
            prev=cur;
        }
        return res; 
    }
};