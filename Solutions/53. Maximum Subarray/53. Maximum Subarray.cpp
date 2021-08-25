class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=INT_MIN,res=INT_MIN;
        for(auto n:nums){
            curr=max(curr,0)+n;
            res=max(curr,res);
        }
        return res;
    }
};

//dp array
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res=dp[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0);
            res=max(dp[i],res);
        }
        return res;
    }
};