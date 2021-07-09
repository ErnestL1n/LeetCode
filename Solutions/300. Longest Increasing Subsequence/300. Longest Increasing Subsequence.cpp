//dp O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=1,n=nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;++i)
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                res=max(res,dp[i]);
            }
        return res;
    }
};

//binary search, O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(const auto& n:nums){
            auto it=lower_bound(res.begin(),res.end(),n);
            if(it==res.end())
                res.push_back(n);
            else
                *it=n;
        }
        return res.size();
    }
};